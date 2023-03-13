#include<stdio.h>		//	comandos in/out
#include<locale.h>		//	Pontuação
#include<windows.h>		//	Título
//#include<conio.h>		//Cores
/*

definir os blocos e as paredes. ( @ / # )
definir um personagem (
movimento do personagem (w a s d / i j k l) (inicialmente por turnos)
definir bombas (o objeto e a range)
atuação das bombas (quebrar blocos e não mapas)
definir quantidade de turnos, que vão estar limpando a tela e mudando o cenário, dentro de um for com variável turnos.
if (botaoapertado==a) {i--; mapa[i][j]=('boneco')};
if (botaoapertado==d) {i++};
if (botaoapertado==s) {j--};
if (botaoapertado==w) {j++};


TL=201					HORIZONTAL=205			TR=187
VERTICAL=186			BOMBA=208				VERTICAL=186
BL=200					HORIZONTAL				BR=188

VAZIO=		176
QUEBRÁVEL=	177
FIXO=		178



*/

int main()
{	
	setlocale(LC_ALL,"Portuguese");
	SetConsoleTitle("PROJETO BOMBERMAN EM C");
		
	char mapa [19] [19], Players[4];
	int i, j, restoi, restoj, quantidadejogadores;
	
//			CORES
//	textcolor(RED);				//para mudar a cor da letra ou
//	textbackground(BLUE);		//para mudar a cor de fundo atrás das letras.

	
	printf("Selecione a Quantidade de players\n");
//							MOSTRA A QUANTIDADE DE PLAYERS
	for(i=0;i!=4;i++)
	{	
		if (i==0)
			{
				printf("( ");
			};
			
		Players[i]=char (i+50);
		printf("%c ",Players[i]);
		
		if (i==3)
			{
				printf(")");
			};
	};
	
	printf("\n");
	scanf("%d", &quantidadejogadores);

	while ((quantidadejogadores<2)||(quantidadejogadores>5))
	{
		printf("Opção inválida, informe um número válido:\n");
		scanf("%d", &quantidadejogadores);
	};
	
	system("cls");
	printf("\n");
//							BOTAR MAPA
	for (i=0;i<19;i++)
	{
		
		for (j=0;j<19;j++)
		{
//							CONTORNO SÓLIDO
			if ((i==0)||(i==18)||(j==0)||(j==18))	{mapa [i] [j]=('x');}
//							QUEBRÁVEIS
			else {mapa [i][j]=('o');};
		
			restoi=i%2;
			restoj=j%2;
//							INTERIOR SÓLIDO
			if ((restoi==0)&&(restoj==0)) 			{mapa [i] [j]=('x');};

		};
		
		
	};
					
		switch (quantidadejogadores)
		{
//									REMOVE PAREDES				local dos players:	p1(1/1)  p2(17/17) p3(17/1) p4(1/17) p5(8/9)
			case 2: {break;}
			case 3: {break;}
			case 4: {break;}
			case 5: {	/*p1*/		mapa [1][2]		=mapa[2][1]		=(' ');
						/*p2*/		mapa [17][16]	=mapa[16][17]	=(' ');
						/*p3*/		mapa [16][1]	=mapa[17][2]	=(' ');
						/*p4*/		mapa [1][16]	=mapa[2][17]	=(' ');
						/*p5*/		mapa [7][8]		=mapa [7][9]	=mapa[7][10]=mapa [9][8]=mapa [9][9]=mapa[9][10]=(' ');	
//									DEFINIR JOGADORES

						/*p1*/		mapa [1][1]		= ('A');
						/*p2*/		mapa [17][17]	= ('B');
						/*p3*/		mapa [17][1]	= ('C');
						/*p4*/		mapa [1][17]	= ('D');
						/*p5*/		mapa [8][9]		= ('E');	break;}
			default: {break;}
		};	
		
	for (i=0;i<19;i++)
	{
		for (j=0;j<19;j++)
		{
			printf("%c ", mapa[i][j]);
		};
		printf("\n");
	};
	

	printf("\n\n");
	system ("pause");
	return 0;
}

/*
BLACK			0
BLUE			1
GREEN			2
CYAN			3
RED				4
MAGENTA			5
BROWN			6
LIGHTGRAY		7
DARKGRAY		8
LIGHTBLUE		9
LIGHTGREEN		10
LIGHTCYAN		11
LIGHTRED		12
LIGHTMAGENTA	13
YELLOW			14
WHITE			15
*/

