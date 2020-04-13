import java.lang.Math;

public class Ponto{
    // ocultamento dos atributas da classes
    private int x, y;
    public Ponto( int x, int y){
        this.x = x;
        this.y = y;
    }
    // sobrescrever o metodo toString da classe pai da classe Ponto
    // para saber mais:https://www.devmedia.com.br/java-object-class-entendendo-a-classe-object/30513

    @Override
    public String toString() {
        return "Ponto{" + "x=" + x + ", y=" + y + '}';
    }

    public boolean Equal(Ponto p){
      return ((this.x == p.x) && (this.y == p.y));
    }

    public double Distance(Ponto p){
      return (Math.sqrt(Math.pow(this.x-p.x,2) + Math.pow(this.y-p.y,2)));
    }


    
}
