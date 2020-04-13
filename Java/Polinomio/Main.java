/*
Entrega de trabalho - Nome do trabalho

Nós,

Bruno Severo Camilo      Tia:41781619



declaramos que

todas as respostas são fruto de nosso próprio trabalho,
não copiamos respostas de colegas externos à equipe,
não disponibilizamos nossas respostas para colegas externos à equipe e
não realizamos quaisquer outras atividades desonestas para nos beneficiar ou prejudicar outros.
*/
class Main {
  public static void main(String[] args) {
    Polinomio Poli = new Polinomio(2);

    Poli.polinomioSet(0,2);
    Poli.polinomioSet(1,2);
    Poli.polinomioSet(2,2);
    
    //Poli.mostra();

    Polinomio Poli2 = new Polinomio(2);

    Poli2.polinomioSet(0,5);
    Poli2.polinomioSet(1,2);
    Poli2.polinomioSet(2,3);
     // 2x² + 1x¹ +2
     // 8 + 2 + 2 = 12

    //Poli2.mostra();

    //Poli.calcPoli(0);
    //Poli2.calcPoli(2);

    //soma de polinomios
    Polinomio soma = Poli.somaPoli(Poli2);

    soma.mostra();


  }
}