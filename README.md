PT - BR: Esse jogo foi criado com a intenção de aplicar os conceitos estudados da linguagem C para aprimorar meus conhecimentos e ganhar experiência prática.
O jogo é baseado no Pac-Man, onde um herói precisa pegar pílulas enquanto foge de fantasmas. As pílulas não se acumulam, então, ao pegar uma pílula, o herói deve buscar algum fantasma que esteja a um raio de ação para destruí-los.
Para mover o herói, basta digitar uma das letras usadas nos jogos de fps em geral: 'W', 'A', 'S' ou 'D' e pressionar enter.
Para explodir a pílula, deve-se pressionar a letra 'B' e depois enter. Ao efetuar o download da pasta do jogo, basta clicar duas vezes no seu executável "fogefoge.exe" para executá-lo.
Caso faça alguma alteração no código e queira compilar os arquivos, abra o cmd e entre na pasta do jogo com o comando: cd "nome_da_pasta". Ao entrar, digite: gcc fogefoge.c mapa.c ui.c -o fogefoge.exe.
Pronto, compilado, basta executar o arquivo pela própria pasta ou digitar foge-foge.exe.

EN: This game was created with the intention of applying the concepts studied in the C language to enhance my knowledge and gain practical experience. 
The game is based on Pac-Man, featuring a hero who needs to collect pills while evading ghosts (in Portuguese, the name is "Foge-Foge" which can be translated as "Run-Run"). 
The pills do not accumulate, so after collecting one, the hero must search for a ghost in your radius of action to destroy it.
To move the hero, simply type one of the letters commonly used in games, 'W', 'A', 'S', or 'D', and press enter. To explode the pill, you must press the letter 'B' and press enter.
To download the game folder, simply double-click on its executable file 'fogefoge.exe' to run it. 
If you make any changes to the code and want to compile the files, open the command prompt (cmd) and navigate to the game folder using the command: cd 'folder_name'. 
Once inside, type: gcc fogefoge.c mapa.c ui.c -o fogefoge.exe. And there you have it, compiled and ready to run the file from the folder itself or by typing fogefoge.exe in cmd.


Raio de ação: O raio de ação seria a menor distância entre o fantasma e o herói antes do fantasma comer o herói, sendo na direita, esquerda, em cima ou em baixo do herói, imagem ilustrando:

Radius of action: The radius of action would be the shortest distance between the ghost and the hero before the ghost eats the hero, being on the right, left, above or below the hero, image illustrating:

![image](https://github.com/DanielArrudas/JogoFoge-Foge/assets/100447748/d53b0882-6f6f-4897-866c-b8cde39de27a)




https://github.com/DanielArrudas/JogoFoge-Foge/
