#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define QTD_ROUPAS 14

// INICIALIZAÇÃO - funções

void Monstruario();
void Info_saldo();
void Fundos();
void Cadastrar();
void Alterar_promocao(int indice);
float Carrinho();
float Preco_produto_selecionado(int indice);
int Senha(int senha_recebida);

// INICIALIZAÇÃO - estrutura
typedef struct
{

    char marca[50];
    char estilo[50];
    char peca[50];
    char cor[50];
    float preco;
    int codigo;
} Promocao;

// INICIALIZAÇÃO - matrizes
char Marca[QTD_ROUPAS][50] = {"Calvin Klein", "Cartier", "Celine", "Chanel", "Dior", "Dolce & Gabbana", "Gucci", "Hermes",
                              "Lacoste", "Louis Vuitton", "Prada", "Saint Laurent", "Supreme", "Versace"
                             };

char Estilo[QTD_ROUPAS][50] = {"Minimalista", "Casual", "Alternativo Hip-hop", "Moda Alta", "Luxo e Extravagancia", "Barroco",
                               "Elegante", "Luxo Ingenuo", "Ecletico", "Sotisficado", "Classe", "Inovacao e Criatividade",
                               "Urban", "Ready- To- Wea"
                              };

char Peca[QTD_ROUPAS][50] = {"Conjunto de Pecas intimas", "Camisa de Botao", "Bucket Hat", "Tailer","Saia" ,"Terno de Alfaiataria",
                             "Casaco de la", "Vestido de Shape Tunica e Leve","Camiseta Polo", "Blazer", "Cashmere",
                             "Jaqueta", "Conjunto de Moletom", "Vestido Versace"
                            };

char Cor[QTD_ROUPAS][50] = {"Vermelho e Branco", "Estampa de Flores Tropicais", "Verde Neon e Preto","Bege", "Estampa Tropical", "Vermelho, Branco e Preto",
                            "Branco e Marrom", "Azul Marinho", "Verde Claro", "Preto", "Rosa Pastel", "Preta e Cinza Escuro",
                            "Vermelho e Verde", "Preto Basico e Dourado"
                           };

float Preco[QTD_ROUPAS] = {150, 189, 99, 1500, 600, 2000, 900, 539, 105, 369, 487, 530, 755, 880};

// INICIALIZAÇÃO - variaveis globais
float total = 0;
float fundos = 0;
int cont = 0;
Promocao promocao[];

int main()
{
    // INICIALIZAÇÃO - variaveis do codigo principal
    int op_menu_p = -1, op_menu_c = -1, op_menu_g = -1, op = -1;
    int i, senha, tam, promocao_escolhida;


    // INTRODUÇÃO
    printf("SEJA BEM-VINDO AO HIGH FASHION STYLES ! :D\n\n");

    // MENU PRINCIPAL
    do
    {
        // Opções do menu principal com base em casos de switch
        printf("INICIO > MENU PRINCIPAL \n");
        printf("_____________________________________\n\n");
        printf("[1] - PARA VER OS PRODUTOS \n");
        printf("[2] - LOGAR NO MENU DO GERENTE \n");
        printf("[3] - ADICIONAR FUNDOS \n");
        printf("[0] - SAIR DO PROGRAMA  \n");
        printf("_____________________________________\n");

        // Pega opção do usuário
        printf(" => INSIRA SUA OPCAO \n");
        scanf("%d",&op_menu_p);
        system("cls || clear"); // Limpar tela

        switch(op_menu_p)
        {

        case 1 :
            Monstruario();

            // MENU SECUNDARIO -
            do
            {    // Opções do menu secundário com base em casos de switch
                printf("MENU SECUNDARIO >>> \n");
                printf("______________________________________\n\n");
                printf("[1] - ADICIONAR AO CARRINHO \n");
                printf("[2] - RETORNAR AO MONSTRUARIO \n");
                printf("[3] - REALIZAR PAGAMENTOS \n");
                printf("[4] - VER INFORMACOES DE CARRINHO E SALDO \n");
                printf("[0] - RETORNAR AO MENU PRINCIPAL \n");
                printf("______________________________________\n");

                // Pega opção do usuário
                printf(" => INSIRA SUA OPCAO \n");
                scanf("%d",&op_menu_c);
                system("cls || clear"); // Limpar tela

                switch(op_menu_c)
                {
                case 1: //MENU SECUNDÁRIO -  Função que acumula de acordo com as compras
                    Carrinho();
                    break;

                case 2: //MENU SECUNDÁRIO - Função que imprime o monstruário
                    Monstruario();
                    break;

                case 3: //MENU SECUNDÁRIO - Função que imprime as informações de saldo e pagamento
                    do
                    {
                        // MENU DE PAGAMENTO -

                         // Opções do menu de pagamento com base em casos de switch
                        Imp_saldo();
                        printf("\n[~ OPCOES DE PAGAMENTO ~] \n");
                        printf("____________________________________________________________\n\n");
                        printf("[1] - PARA CONFIRMAR PAGAMENTO DO VALOR TOTAL DO CARRINHO \n");
                        printf("[2] - PARA ADICIONAR FUNDOS \n");
                        printf("[0] - RETORNAR \n");
                        printf("____________________________________________________________\n\n");

                        // Pega opção do usuário
                        printf(" => INSIRA SUA OPCAO \n");
                        scanf("%d",&op);
                        system("cls || clear");


                        switch(op)
                        {

                        case 1: // MENU DE PAGAMENTO - Realiza pagamento
                            if((fundos - total) >= 0 )
                            {
                                if(total == 0)
                                {
                                    printf(" => VOCE NAO TEM NENHUM VALOR A SER PAGO \n");
                                }
                                else
                                {
                                    system("cls || clear");

                                    printf(" => OPERACAO DE DEBITO AUTOMATICO BEM SUCEDIDA \n\n\n");

                                    fundos = fundos - total;
                                    total = 0;

                                }

                            }
                            else
                            {
                                system("cls || clear");
                                printf(" => SALDO INSUFICIENTE \n");
                                printf("_____________________________________\n\n");
                                Imp_saldo();
                            }
                            system("pause");
                            system("cls || clear");
                            break;

                        case 2: // MENU DE PAGAMENTO - Adiciona fundos
                            Fundos();
                            break;

                        case 0: // MENU DE PAGAMENTO - Encerra processos
                            break;
                        }

                    }
                    while(op != 0);

                    break;

                case 4:
                    Imp_saldo();
                    system("pause");
                    system("cls || clear");
                    break;


                case 0: //MENU SECUNDÁRIO - Encerra processos
                    break;

                }
            }
            while(op_menu_c != 0);

            break;

        case 2: //MENU PRINCIPAL - LOGIN NO MENU DO GERENTE

            printf("______________________________________\n\n");
            printf("PROCESO DE VALIDACAO DO LOGIN: \n");
            printf("INSIRA A SENHA: \n");
            scanf("%d",&senha);

            if(Senha(senha)) // saber se a senha é válida
            {
                printf(" =-> SENHA VALIDADA \n");
                printf("BEM VINDO AO MENU DO GERENTE! \n");
                printf("______________________________________\n\n");
                system("pause");
                system("cls || clear");

                do
                {
                    printf("MENU DO GERENTE >>> \n"); // MENU DO GERENTE EM CASOS DE SWITCH
                    printf("______________________________________\n\n");
                    printf("[1] - CADASTRAR UMA PROMOCAO \n");
                    printf("[2] - ALTERAR INFORMACOES DA PROMOCAO \n");
                    printf("[0] - RETORNAR AO MENU PRINCIPAL \n");
                    printf("______________________________________\n");

                    printf(" => INSIRA SUA OPCAO \n");
                    scanf("%d",&op_menu_g);
                    system("cls || clear"); // Limpar tela

                    switch(op_menu_g)
                    {
                    case 1: // MENU DO GERENTE - OPÇÃO PARA CADASTRAR EM VALORES ACUMULATIVOS

                        if(cont)
                        {
                            printf("[ %d PROMOCOES CADASTRADAS - DO CODIGO 0 ATE O %d ] \n",cont,cont-1);
                            printf("[~ NOVAS INFORMACOES PODERAO SER CADASTRADAS NO PROXIMO CODIGO => %d ] \n\n",cont);
                        }

                        printf("* EM ATE QUAL CODIGO DESEJA CADASTRAR?  ");
                        scanf("%d",&tam);
                        system("cls || clear");

                        if(tam<cont)
                        {
                            printf("POR FAVOR DIGITE UM CODIGO QUE AINDA NAO ESTA OCUPADO \n");
                            system("pause");
                            system("cls || clear");

                        }
                        else
                        {

                            Cadastrar(tam);

                            printf("CADASTRO DE %d PRODUTOS COMPLETOS \n",cont);
                            system("pause");
                            system("cls || clear");

                        }
                        break;

                    case 2: // MENU DO GERENTE - OPÇÃO DE ALTERAR AS PROMOÇÕES DISPONÍVEIS
                        if(cont)
                        {

                            system("cls || clear");
                            printf(" [~ PROMOCOES DISPONIVEIS ~] \n\n");

                            for(i = 0; i < cont; i++)
                            {

                                printf(" [-CODIGO: %d \n",i);
                                printf(" [-MARCA: %s ", promocao[i].marca);
                                printf("[-ESTILO: %s ", promocao[i].estilo);
                                printf("[-PECA: %s ", promocao[i].peca);
                                printf("[-CORES: %s ", promocao[i].cor);
                                printf("[-PRECO: R$%.2f \n", promocao[i].preco);
                                printf("\n\n");
                            }

                            printf("* INSIRA O CODIGO DA PROMOCAO DESEJA ALTERAR:  ");
                            scanf("%d",&promocao_escolhida);

                            if(promocao_escolhida > cont-1 || promocao_escolhida < 0)
                            {

                                printf("CODIGO INVALIDO \n");
                            }
                            else
                            {
                                Alterar_promocao(promocao_escolhida);
                            }


                        }
                        else
                        {

                            printf(" [~ NENHUMA PROMOCAO CADASTRADA ~] \n");
                            system("pause");
                            system("cls || clear");
                        }

                        break;

                    case 0:
                        break;
                    }

                }
                while(op_menu_g != 0);
            }


            break;

        case 3: // MENU PRINCIPAL - ADICIONAR FUNDOS
            Fundos();
            break;


        case 0: // MENU PRINCIPAL - SAIR DO PROGRAMA
            if(total != 0)
            {
                printf("\n_______________________________________________________\n\n");
                printf("=> ATENCAO!!! VOCE TEM FATURAS PENDENTES NO CARRINHO!");
                printf("\n_______________________________________________________\n\n");

                system("pause");
                system("cls || clear");

                op_menu_p = 1;

            }
            else return 0;

            break;
        }

    }
    while (op_menu_p != 0);
    return 0;

}
// FUNÇÃO MONSTRUÁRIO - Imprime as informações do monstruário salvas em matrizes e em structs se caso houver dados registrados.
void Monstruario()
{
    int i;

    printf("MENU SECUNDARIO > MONSTRUARIO DE ROUPAS \n");
    printf("[~ INFORMACOES DOS PRODUTOS: ~]\n\n");

    for( i = 0; i < QTD_ROUPAS; i++ )
    {
        printf("[-CODIGO: %d \n",i);
        printf("[-MARCA: %s \n", Marca[i]);
        printf("[-ESTILO: %s \n", Estilo[i]);
        printf("[-PECA: %s \n", Peca[i]);
        printf("[-CORES: %s \n", Cor[i]);
        printf("[-PRECO: R$%.2f \n",Preco[i]);
        printf("\n\n");
    }

    if(cont)
    {
        printf(" [~ PROMOCOES DISPONIVEIS ~] \n\n");

        for(i = 0; i < cont; i++)
        {
            printf(" [-CODIGO: %d \n",(QTD_ROUPAS+i));
            printf(" [-MARCA: %s ", promocao[i].marca);
            printf("[-ESTILO: %s ", promocao[i].estilo);
            printf("[-PECA: %s ", promocao[i].peca);
            printf("[-CORES: %s ", promocao[i].cor);
            printf("[-PRECO: R$%.2f \n", promocao[i].preco);
            printf("\n\n");
        }
    }

}

// FUNÇÃO CARRINHO - Le os valores de código, valida e passa para outra função retornar o valor do preço.
float Carrinho()
{

    int codigo_escolhido, i, unid;
    float preco_produto;

    printf(">>> CARRINHO DE COMPRAS \n");
    printf("_____________________________________\n\n");
    printf("INFORME O CODIGO DO PRODUTO: ");
    scanf("%d",&codigo_escolhido);

    if (codigo_escolhido >= (QTD_ROUPAS+cont) || codigo_escolhido < 0)
    {
        printf("CODIGO INVALIDO! \n");

        system("pause");
        system("cls || clear");

    }
    else
    {

        for(i = 0; i < (QTD_ROUPAS+cont-1); i++)
        {

            if(codigo_escolhido == i)
                break;
        }

        preco_produto = Preco_produto_selecionado(i);

        printf("_____________________________________\n");
        printf("* INFORME QUANTAS UNIDADES DESEJA: ");
        scanf("%d",&unid);

        // Operação acumulativa
        total = total + (preco_produto * unid);

        printf("\n => PRECO ATUALIZADO DO CARRINHO: RS%.2f \n", total); // Imprime o valor total acumulado
        printf("________________________________________________\n");
        system("pause"); // Pausar programa para o usuário poder ler antes que limpe a tela
        system("cls || clear"); // Limpar tela

    }
}

// FUNÇÃO SENHA - recebe uma senha e retorna valor 1 se caso a senha for válida.
int Senha(senha_recebida)
{

    int validacao;

    if(senha_recebida == 123)
    {
        validacao = 1;
        return validacao;
    }
    else
    {

        printf("\n\n =-> SENHA INVALIDA! \n");
        system("pause");
        system("cls || clear");

    }

}

void Fundos() //FUNÇÃO FUNDOS - adiciona dinheiro fictício para pagar os valores de compra no programa.
{
    float adc_saldo;
    printf("_____________________________________\n\n");
    printf(" => SALDO ATUAL: %2.f R$ \n",fundos);
    printf("_____________________________________\n\n");
    printf("* INFORME A QUANTIDADE DE SALDO QUE DESEJA ADICIONAR: \n");
    scanf("%f",&adc_saldo);

    if(adc_saldo < 0)
    {

        printf("NAO FOI POSSIVEL ADICIONAR ESSE VALOR \n");

    }
    else
    {
        fundos = fundos + adc_saldo;
        printf("\n\n\nOPERACAO BEM SUCEDIDA! \n");
        printf("_____________________________________\n\n");
        printf(" => QUANTIDADE ADICIONADA: %2.f R$ \n", adc_saldo);
        printf("_____________________________________\n\n");
    }
    system("pause");
    system("cls || clear");
}

void Imp_saldo() // FUNÇÃO IMPRIMIR SALDO - imprime informações de saldo e preço do carrinho do momento em que for executada.
{

    printf(">>> INFORMACOES DE SALDO \n\n");
    printf(" => SALDO ATUAL: %2.f R$ \n",fundos);
    printf(" => VALOR ATUAL DO CARRINHO: %2.f R$ \n",total);
    printf("_____________________________________\n\n\n");
}

// FUNÇÃO CADASTRAR - recebe um tamanho e cadastra promoções, acumulando o código delas em uma variável contadora.
void Cadastrar(int tam)
{
    int i;
    printf("[DO CODIGO %d ATE %d] \n",cont, tam);
    printf("__________________________________\n\n");

    for(i = cont; i <= tam; i++)
    {
        printf("CADASTRANDO PROMOCAO DE CODIGO %d \n",cont);
        printf("__________________________________\n\n");
        fflush(stdin);

        printf(" [-INSIRA O MODELO-] => ");
        fgets(promocao[i].peca, 50, stdin);

        printf(" [-INSIRA A MARCA-] => ");
        fgets(promocao[i].marca, 50, stdin);

        printf(" [-INSIRA AS CORES-] => ");
        fgets(promocao[i].cor, 50, stdin);

        printf(" [-INSIRA O ESTILO-] => ");
        fgets(promocao[i].estilo, 50, stdin);

        printf(" [-INSIRA O PRECO-] => ");
        scanf("%f",&promocao[i].preco);
        getchar();
        cont++;
        system("cls || clear");

    }
}

// FUNÇÃO ALTERAR - altera as informações das promoções substituindo as mesmas por valores digitados pelo usuário.
void Alterar_promocao(indice)
{
    int menu;

    do
    {
        system("cls || clear");
        printf("[PROMOCAO SELECIONADA DE CODIGO %d] \n\n",indice);

        printf(" [1] - MARCA: %s ", promocao[indice].marca);
        printf("[2] - ESTILO: %s ", promocao[indice].estilo);
        printf("[3] - PECA: %s ", promocao[indice].peca);
        printf("[4] - CORES: %s ", promocao[indice].cor);
        printf("[5] - PRECO: R$%.2f \n", promocao[indice].preco);
        printf(" [0] - PARA CANCELAR ALTERACAO \n");
        printf("\n\n");

        printf("=> DIGITE O VALOR DA LINHA PARA ALTERAR AS INFORMACOES:  ");
        scanf("%d",&menu);
        printf("\n\n______________________________________________________\n\n");
        fflush(stdin);


        switch(menu)
        {

        case 1:

            printf("[INFORMACAO A SER ALTERADA] => MARCA \n");
            printf("INFORMACAO ANTIGA: %s \n\n",promocao[indice].marca);

            printf("INSIRA A NOVA INFORMACAO: \n");
            fgets(promocao[indice].marca, 50, stdin);
            getchar();

            break;

        case 2:
            printf("[INFORMACAO A SER ALTERADA] => ESTILO \n");
            printf("INFORMACAO ANTIGA: %s \n\n",promocao[indice].estilo);

            printf("INSIRA A NOVA INFORMACAO: \n");
            fgets(promocao[indice].estilo, 50, stdin);
            getchar();
            break;

        case 3:
            printf("[INFORMACAO A SER ALTERADA] => PECA \n");
            printf("INFORMACAO ANTIGA: %s \n\n",promocao[indice].peca);

            printf("INSIRA A NOVA INFORMACAO: \n");
            fgets(promocao[indice].peca, 50, stdin);
            getchar();
            break;

        case 4:
            printf("[INFORMACAO A SER ALTERADA] => CORES \n");
            printf("INFORMACAO ANTIGA: %s \n\n",promocao[indice].cor);

            printf("INSIRA A NOVA INFORMACAO: \n");
            fgets(promocao[indice].cor, 50, stdin);
            getchar();
            break;

        case 5:
            printf("[INFORMACAO A SER ALTERADA] => PRECO \n");
            printf("INFORMACAO ANTIGA: R$%.2f \n\n",promocao[indice].preco);

            printf("INSIRA A NOVA INFORMACAO: \n");
            scanf("%f",&promocao[indice].preco);
            getchar();
            break;

        case 0:
            system("cls || clear");
            break;
        }

    }
    while(menu != 0);
}

// FUNÇÃO PREÇO - recebe o código após a validação feita na FUNÇÃO CARRINHO e indentifica se está registrado em matrizes ou struct, retornando o preço e imprimindo as informações do produto.
float Preco_produto_selecionado(int indice)
{
    float valor;

    if(indice > QTD_ROUPAS-1)
    {

        indice = indice - QTD_ROUPAS;

        printf("_____________________________________\n");
        printf("INFORMACOES DO PRODUTO SELECIONADO: \n\n");
        printf(" [-MARCA: %s ", promocao[indice].marca);
        printf("[-ESTILO: %s ", promocao[indice].estilo);
        printf("[-PECA: %s ", promocao[indice].peca);
        printf("[-CORES: %s ", promocao[indice].cor);
        printf("[-PRECO: R$%.2f \n", promocao[indice].preco);
        printf("_____________________________________\n");

        valor = promocao[indice].preco;

    }
    else
    {

        printf("_____________________________________\n");
        printf("INFORMACOES DO PRODUTO SELECIONADO: \n\n");
        printf("[-MARCA: %s \n", Marca[indice]);
        printf("[-ESTILO: %s \n", Estilo[indice]);
        printf("[-PECA: %s \n", Peca[indice]);
        printf("[-CORES: %s \n", Cor[indice]);
        printf("[-PRECO: R$%.2f \n",Preco[indice]);
        printf("_____________________________________\n");

        valor = Preco[indice];

    }

    return valor;
}

