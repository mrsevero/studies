public class Polinomio{
 // vetor para representar os termos do polinomio
 private double termos[];
 private int grau;
 // recebe um grau de polinômio e instancia os termos do
 // polinômio
 public Polinomio(int grau){
   this.termos = new double[grau+1];
   this.grau = grau;
}

 // imprime o polinômio, será explica a seguir
 public void mostra(){
   System.out.printf("\n");
   for (int i = this.grau; i>=0;i--){
     System.out.printf("%.2fX^%d ",this.termos[i],i);
   }

 }

 public void polinomioSet(int posicao, double numero){
   this.termos[posicao] = numero;
 }

 public void calcPoli(double valor){
  double resultado = 0;
  for(int i = 0; i<=this.grau;i++){
     resultado = resultado + this.termos[i]*(Math.pow(valor,i));
  }
  
  
  System.out.printf("%.3f",resultado);

  System.out.printf("\n");
   
 }

 public Polinomio somaPoli(Polinomio p){
   //Verifica qual o maior polinomio
   if(this.grau < p.grau){
    Polinomio result = new Polinomio(p.grau);

    for (int i = 0; i<=this.grau;i++){
      result.polinomioSet(i,this.termos[i]+p.termos[i]);
    }
    for (int i = this.grau+1; i<=p.grau;i++){
      result.polinomioSet(i,p.termos[i]);
    }
    return result;
   }
   else if (p.grau < this.grau){
    Polinomio result = new Polinomio(this.grau);

    for (int i = 0; i<=p.grau;i++){
      result.polinomioSet(i,this.termos[i]+p.termos[i]);
    }
    for (int i = p.grau+1; i<=this.grau;i++){
      result.polinomioSet(i,this.termos[i]);
    }
    return result;
   }
   else{
    Polinomio result = new Polinomio(p.grau);
    
    for (int i = 0; i<=p.grau;i++){
      result.polinomioSet(i,this.termos[i]+p.termos[i]);
    }
    return result;

   }
 }
 
  public void somanoPoli(double valor, int indice){
   this.termos[indice] += valor;
 }

 public Polinomio multPoli(Polinomio p){

   Polinomio multresult = new Polinomio(p.grau+this.grau);

   for (int i = 0 ; i<=this.grau; i++){
     for (int j = 0; j<=p.grau;j++){
       multresult.somanoPoli(this.termos[i]*p.termos[j], i+j);       
     }
   }
   return multresult;

 }

}
