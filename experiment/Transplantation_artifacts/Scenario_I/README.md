README

## SCRIPT DO ESTUDO DE CASO

A porposta é realizarmos o transplante da funcionalidade write_archive disponibel no sistema Mytar, um gerenciador de arquivo, e inserirmos no editor de texto NEATVI. A função write_archive cria e escrece o conteúdo de um arquivo qualquer para um arquivo *.TAR. Para isso o Mytar deve receber como entrada o nome do arquivo de entrada e o nome do arquivo de saida. No entanto, para que a feature write_archive funcione corretamenta no sistema hospedeiro ela precisará que a estrutura archive seja carregada, o que é feito pelas demais funcões chamdas antes de sua execução.

### DADOS DISPONIBILIZADOS

Como são sistemas distintos será necessario a adaptação do codigo que implementa o ponto de entrada da feature ( ou seja, a função write_archive) para o ponto de inserção no sistema NEATVI, com base nas seguintes informações:

1. Ponto de entrada da feature: função write_archive do arquivo append.c
2. Ponto de inserção no sistema hospedeiro: ponto definido pela notação com __ADDGRAFTHERE__JUSTHERE no arquivo ex.c
3. O grafico de chamda da feature disponivel tanto no sua documentação em Documentation/Donor_documentation  como pode ser visualizado através da imagem Documentation/CALL_GRAPH.png
4. test_suit: um conjunto de testes unitarios que poderão ser utilizados para auxiliar na adaptação e execução da feature antes de sua inserção.

### Teste de valiação do transplante
   Após o transplante você deverá executar o comando: make dentro do diretorio NEATVI. Isso gerará um arquivo executavel vi.exec. Em seguida execute o comando ./vi text.txt e insira o seguites comandos:
        1. i para entrar no modo inserção
        2. Insira o nome do arquivo que deseja gerar a copia .TAR  
        3. Insira o domando :wa. Este comando irá executar a feature transplantada e deverá criar um arquivo com o nome informado e a extesão .TAR

OBS: Você poderá mover para o diretorio do sistema hospedeiro qualquer arquivo que julgue ser necessário para a execução da feature, no entanto, como se trata de um processo de extração da feature recomendamos que copie somente as funções, variaveis globais, diretivas e declaração de bibliotéca que for utilizado pela feature. 

Você poderá utilizar a IDE que se sentir confortável ou apenas um editor de texto simples. 
Não será necessario a execução do sistema doador. A proposta é que ao observar o codigo e a documentação, seja possivel extrair a funcionalidade.

Criamos a chamada da função que servirá de interface entre a feature e o sistema hospedeiro. Você poderá colocar o codigo que julgar necessário para inicializar a feature entro dela.
