#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Função para posicionar o cursor em um determinado ponto da tela
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Função para construir a tela padrão
void tela()
{
	int lin;
	int col;

	system("cls");
	system("color 5");

	for (lin = 1; lin < 25; lin++)
	{
		gotoxy(1, lin);
		printf("|");
		gotoxy(79, lin);
		printf("|");
	}

	for (col = 1; col < 80; col++)
	{
		gotoxy(col, 1);
		printf("-");
		gotoxy(col, 4);
		printf("-");
		gotoxy(col, 22);
		printf("-");
		gotoxy(col, 24);
		printf("-");
	}

	gotoxy(1, 1);
	printf("+");
	gotoxy(79, 1);
	printf("+");

	gotoxy(1, 4);
	printf("+");
	gotoxy(79, 4);
	printf("+");

	gotoxy(1, 22);
	printf("+");
	gotoxy(79, 22);
	printf("+");

	gotoxy(3, 2);
	printf("UNICV");
	gotoxy(60, 2);
	printf("ESTRUTURA DE DADOS | ");
	gotoxy(3, 3);
	printf("SISTEMA DE CALCULO DE AREAS");
	gotoxy(62, 3);
	printf("Matheus Moreira  | ");
	gotoxy(2, 23);
	printf("MSG");
}

// Função para cálculo da área do círculo
void circulo(int *opcao)
{
	float raio, area;
	do
	{
		tela();
		gotoxy(7, 23);
		printf("Calculando...");
		// pedindo o raio
		gotoxy(28, 10);
		printf("Digite o Raio...: ");
		gotoxy(46, 10);
		scanf("%f", &raio);
		// calculo
		area = 3.1416 * raio * raio;
		// mostrar forma e resultado
		gotoxy(28, 12);
		printf("A formula e.....: Area = pi * r*2");
		gotoxy(28, 14);
		printf("E o Resultado...: %.2f", area);
		// opções
		gotoxy(7, 23);
		printf("1 = Calcular outro | 2 = Voltar ao menu ");
		scanf("%d", opcao);
	} while (*opcao == 1);
}

// Função para cálculo da área do retângulo
void retangulo(int *opcao)
{
	float lado, altura, area;
	do
	{
		tela();
		gotoxy(7, 23);
		printf("Calculando...");
		// pedindo o lado
		gotoxy(28, 10);
		printf("Digite o Lado.....: ");
		gotoxy(48, 10);
		scanf("%f", &lado);
		// pedindo a altura
		gotoxy(28, 12);
		printf("Digite a Altura...: ");
		gotoxy(48, 12);
		scanf("%f", &altura);
		// calculo
		area = lado * altura;
		// mostrando na tela
		gotoxy(28, 14);
		printf("A formula e.......: Area = Lado * Altura");
		gotoxy(28, 16);
		printf("E o Resultado.....: %.2f", area);
		// opções
		gotoxy(7, 23);
		printf("1 = Calcular outro | 2 = Voltar ao menu ");
		scanf("%d", opcao);
	} while (*opcao == 1);
}

// Função para cálculo da área do trapézio
void trapezio(int *opcao)
{
	float base_maior, base_menor, altura, area;
	do
	{
		tela();
		gotoxy(7, 23);
		printf("Calculando...");
		// pedir as bases
		gotoxy(28, 10);
		printf("Digite a Base maior...: ");
		gotoxy(52, 10);
		scanf("%f", &base_maior);

		gotoxy(28, 12);
		printf("Digite a Base menor..: ");
		gotoxy(52, 12);
		scanf("%f", &base_menor);
		// pedindo altura
		gotoxy(28, 14);
		printf("Digite a Altura.......: ");
		gotoxy(52, 14);
		scanf("%f", &altura);
		// calculo
		area = ((base_maior + base_menor) * altura) / 2;
		// resultado e formula
		gotoxy(28, 16);
		printf("A formula e...........: Area = (Base maior + Base menor) * Altura / 2");
		gotoxy(28, 18);
		printf("E o Resultado.........: %.2f", area);
		// opções
		gotoxy(7, 23);
		printf("1 = Calcular outro | 2 = Voltar ao menu ");
		scanf("%d", opcao);
	} while (*opcao == 1);
}

// Função para cálculo da área do triângulo
void triangulo(int *opcao)
{
	float base, altura, area;
	do
	{
		tela();
		gotoxy(7, 23);
		printf("Calculando...");
		// pedindo base e altura
		gotoxy(28, 10);
		printf("Digite a Base.....: ");
		gotoxy(48, 10);
		scanf("%f", &base);

		gotoxy(28, 12);
		printf("Digite a Altura...: ");
		gotoxy(48, 12);
		scanf("%f", &altura);
		// calculo
		area = (base * altura) / 2;
		// resultado e formula
		gotoxy(28, 14);
		printf("A formula e.......: Area = (Base * Altura) / 2");
		gotoxy(28, 16);
		printf("E o Resultado.....: %.2f", area);
		// opções
		gotoxy(7, 23);
		printf("1 = Calcular outro | 2 = Voltar ao menu ");
		scanf("%d", opcao);
	} while (*opcao == 1);
}

// Programa principal
int main()
{
	int opcao;

	do
	{
		// menu principal
		tela();
		gotoxy(25, 10);
		printf("1 - Calculo da area do circulo");
		gotoxy(25, 12);
		printf("2 - Calculo da area do retangulo");
		gotoxy(25, 14);
		printf("3 - Calculo da area do trapezio");
		gotoxy(25, 16);
		printf("4 - Calculo da area do triangulo");
		gotoxy(25, 18);
		printf("5 - Sair");

		gotoxy(2, 23);
		printf("Digite sua opcao:");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			circulo(&opcao);
			break;

		case 2:
			retangulo(&opcao);
			break;

		case 3:
			trapezio(&opcao);
			break;

		case 4:
			triangulo(&opcao);
			break;

		case 5:
			gotoxy(7, 23);
			printf("Saindo do programa...");
			getch();
			break;
		default:
			gotoxy(7, 23);
			printf("Opcao Invalida. Tente Novamente.");
			getch();
			break;
		}
	} while (opcao != 5);

	return 0;
}