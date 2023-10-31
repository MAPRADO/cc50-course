# Simulate a sports tournament

import csv
import sys
import random

# Number of simulations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    filename = sys.argv[1]

    with open(filename, 'r') as file:
        reader_csv = csv.DictReader(file)
        for team in reader_csv:
            team["rating"] = int(team["rating"])
            reader_csv = dict([('team', 'rating')])
            teams.append(team)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    # Simular N torneios e acompanhar a contagem das vitórias
    for i in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1

    # Print each team's chances of winning, according to simulation
    # Imprimir as chances de vitória de cada equipe, de acordo com a simulação
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    # Simular um jogo. Retornar True se o time1 vencer, Falso caso contrário
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    # Simular uma rodada. Devolver uma lista das equipes vencedoras
    winners = []

    # Simulate games for all pairs of teams
    # Simular jogos para todos os pares de equipes
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO Simular um torneio. Retornar nome do time vencedor
    # Simular as fases seguintes entre os vencedores até o final

    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["team"]


if __name__ == "__main__":
    main()
