public class presidente extends funcionario{
  private double adicional_whisky, adicional_helicoptero,adicional_adicional;

  public presidente( int ID, String nome, int departamento, double salario){
    super(ID, nome, departamento, salario, 0);
    this.adicional_whisky=0.9;
    this.adicional_helicoptero=0.7;
    this.adicional_adicional=3.8;
}
  void setAdicionalPresidente(double novo_percentual){
    adicional_whisky=0.9*(1+novo_percentual);
    adicional_helicoptero=0.7*(1+novo_percentual);
    adicional_adicional=3.8*(1+novo_percentual);
  }
  double pagamento(){
  // Calcula o salário líquido
    return(getSalario()*((1-getPrevidencia())+this.adicional_whisky+this.adicional_helicoptero
    + this.adicional_adicional));
    }
}
