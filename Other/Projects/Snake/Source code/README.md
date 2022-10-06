================SNAKE GAME================
        ---A.K.A. Jogo da cobrinha---
    
    ---Detalhes: 
        ---Para o funcionamento do jogo, o usuario deve entrar no diretorio "RunScripts", digitar no terminal:
        
            $chmod +777 run_map_1.sh && run_map_2.sh && run_map_3.sh
            $./run_map_1.sh <ou run_map_2.sh ou run_map_3.sh>---

        ---O jogo deve ser executado com o terminal---
        ---A cabeça da cobrinha eh respresentada por setas '>', '<', '^' e 'v'.---
        ---O corpo da cobrinha eh respresentada por 'o'---
        ---A comida eh respresentada por '*' e o bonus de dinheiro '$'---
        ---Os tuneis/portais sao respresentados por '@'. Caso o usuario entre em um, saira no outro na mesma direcao com a qual entrou.---
        ---As pareses são respresentadas por '#'. Caso o jogador acerte a parede ou o proprio corpo ele perde o jogo.---
        ---Os comandos validos sao: 'w', 'a', 's', 'd'---
        ---Caso deseje ver as informacoes geradas apos a ultima jogada no mapa, os aquivos gerados se encontram na pasta "saida", encontrada na pasta mapa_<numero_do_mapa>---
            >Os Arquivos de saida sao: HeatMap.txt, Ranking.txt, Resumo.txt, Inicializacao.txt e Estatisticas.txt---

    ---Objetivo: Ganhar o maximo de pontos possiveis---

    ---Ejoy ;)---


-->Realizado na disciplina de Prog.I (1o Periodo) da Universidade Federal do Espirito Santo (UFES).
-->Objetivo: Aplicar conhecimentos de modularizacao, criacao e manipulacao de tipos de dados definidos pelo usuario, logica e manipulacao de arquivos.
-->Extra: Organizacao de codigo por meio da separacao em bilbiotecas com as funcoes proprias criadas para esse problema.

---Autor do codigo: Gabriel Zuany Duarte Vargas---
---Data: 2022, Agosto---
---Versao: 1.2---

---Ultima atualizacao: 13/08/2022 (V 1.1 -> V 1.2)---
    --- 1. Code refactoring;
    --- 2. Separation of functions in created libraries;
    --- 3.Creation of execution scripts.
    --- 4.Project folder organization.
    
=============OPERAVEL, POR ENQUANTO, APENAS NO LINUX;==============