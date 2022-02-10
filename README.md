# Prog_Rover :3rd_place_medal: 🚗

## Sobre o projeto
Este foi um dos primeiros projetos que fizemos na faculdade. Este projeto tinha 2 objetivos, sendo um deles em fazer um carro (Rover) seguir/andar sob linhas brancas sem se perder ou sair do caminho estipulado. 
E o outro objetivo era fazer com que o carro desviasse de objetos a sua frente para evitar colisões. Para a construção deste projeto, montamos o Rover com 3 sensores infravermelhos na frente do carrinho apontados para baixo, 
3 sensores de distância  alocados na frente do Rover, uma placa arduino e fios macho/fêmea para ligação dos sensores/motores ao arduino.

## Como funciona
No objetivo de seguir um caminho determinado pela linha branca, o Rover seguia em linha reta caso os 3 sensores infravermelhos estiverem detectando a linha logo abaixo deles. Caso o sensor da direita ou esquerda não detecte a 
linha branca, o motor da roda que estiver ao lado oposto do sensor infravermelho irá rodar em uma velocidade menor que os motores do lado do infravermelho que deixou de detectar a linha, fazendo com que o Rover consiga fazer curvas.
Já no objetivo de desviar de objetos, nosso rover aplica a mesma lógica que o objetivo anterior, porém dessa vez caso ele detecte um objeto. Se o objeto estiver sendo detectado pelos 3 sensores, o Rover rotaciona para traz (da ré)
por alguns segundos e vira 180º ( um lado dele gira em sentido horario e o outro em sentido anti-horario).

<h>

## Tecnologias utilizadas
##### C++
<h>


## Objetivos Rover

- [X] Seguir linha
- [X] Desviar de objetos
- [X] Dar zerinho (Extra)

## Autores
- Victor Matheus Silva Lima
- Higor Frade

## Orientador e professor
Marco Antonio Miquelino @ Unifaj
