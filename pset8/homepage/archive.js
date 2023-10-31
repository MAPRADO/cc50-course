
// Fazer a mudança de página via botão principal na home
// Versão mais simples usando no html: <button onclick="NewTab()"></button>
/* function NewTab() {
    window.location.href = "my_services.html";
} */


// Versão mais elaborada usando o "addEventListener"
/* const button = document.getElementById('button-page');

button.addEventListener('click', function(event) {
  window.location.href = "my_services.html";
}); */


// Versão usando uma função e o "window.onload"
function novaAba() {
    window.location.href = "my_services.html";
}

window.onload = function () {
    let botaoAlerta = document.getElementById('button-page');

    botaoAlerta.onclick = function () {
        novaAba();
    };
}


// Fazer abertura de página via ícones mídias sociais
// Função para abrir nova guia para mídias sociais

/* function midiaSociais()
{
    window.open('https://www.facebook.com');
        return false;
}
    window.onload = function(){
    let midias = document.getElementsByClassName("face");

    midias.onclick = function () {
        midiaSociais();
    }
} */

function midiaSociais1() {
    if (document.getElementsByClassName("face")) {
        window.open('https://www.facebook.com');
        return false;
    }
}

function midiaSociais2() {
    if (document.getElementsByClassName("insta")) {
        window.open('https://www.instagram.com');
        return false;
    }
}

function midiaSociais3() {
    if (document.getElementsByClassName("twit")) {
        window.open('https://twitter.com');
        return false;
    }
}

function midiaSociais4() {
    if (document.getElementsByClassName("whats")) {
        window.open('https://www.whatsapp.com');
        return false;
    }
}