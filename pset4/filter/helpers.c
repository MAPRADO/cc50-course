#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Comb through each row
    for (int i = 0; i < height; i++)
    {
        // Comb through each column
        for (int j = 0; j < width; j++)
        {
            // Find the average value
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Comb through each row
    for (int i = 0; i < height; i++)
    {
        // Comb through each column
        for (int j = 0; j < width / 2; j++)
        {
            // Inverting the matrix positions
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// >>>>> Blur image <<<<<
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary copy of the image
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // Iterate through each row
    for (int i = 0; i < height; i++)
    {
        // Iterate through each column
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float counter = 0.00;

            // Get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // Check if neighbouring pixels is valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // Get image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                // Calculate average of neighbouring pixels
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    // Copy new pixel original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// >>>>> Detect edges <<<<<
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary copy of the image
    RGBTRIPLE temp[height][width];

    // Initialize the 2-dimensional array, Gx and Gy

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int iCoords[] = {i - 1, i, i + 1};
            int jCoords[] = {j - 1, j, j + 1};
            float Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            float Gy_red = 0, Gy_green = 0, Gy_blue = 0;

            // Get neighbouring pixels
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int currI = iCoords[x];
                    int currJ = jCoords[y];

                    // Get the neighboring pixels outside the image and consider them as black
                    if (currI >= 0 && currI < height && currJ >= 0 && currJ < width)
                    {
                        RGBTRIPLE pixel = image[currI][currJ];

                        Gx_red += Gx[x][y] * pixel.rgbtRed;
                        Gx_green += Gx[x][y] * pixel.rgbtGreen;
                        Gx_blue += Gx[x][y] * pixel.rgbtBlue;

                        Gy_red += Gy[x][y] * pixel.rgbtRed;
                        Gy_green += Gy[x][y] * pixel.rgbtGreen;
                        Gy_blue += Gy[x][y] * pixel.rgbtBlue;
                    }
                }
            }

            // Now apply the sqrt function to the Gx and Gy
            int newRed = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int newGreen = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int newBlue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            temp[i][j].rgbtRed = newRed > 255 ? 255 : newRed;
            temp[i][j].rgbtGreen = newGreen > 255 ? 255 : newGreen;
            temp[i][j].rgbtBlue = newBlue > 255 ? 255 : newBlue;
        }
    }

    // Copy new pixel original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
