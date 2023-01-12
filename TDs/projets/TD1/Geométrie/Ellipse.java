package geometrie;

public class Ellipse extends Geometrie{
    protected String type;
    protected float cote1;
    protected float cote2;
    
    public float getCote1(){
        return cote1;
    }
    public float setCote1(float cote1){
        this.cote1 = cote1;
    }
    
    public float getCote2(){
        return cote2;
    }
    public float setCote2(float cote2){
        this.cote2 = cote2;
    }
    
    public void setType(String type){
        this.type = type;
    }
    
     public Ellipse(){
        this.cote1 = 0;
        this.cote3 = 0;
        this.type = "Ellipse";
    }
    
    public Ellipse(float cote1, float cote2, String type){
        this.cote1 = cote1;
        this.cote2 = cote2;
        this.type = type;
    }
    
    public float calculAire(){
        return (float)(Math.PI.cote1.cote2);
    }
    
    public float calculPerimetre(){
        return (float) (2*Math.PI*Math.sqrt((cote1*cote1+cote2*cote2)/2));
    }
    
    public String monType(){
        return type + "-->" + super.monType();
    } 
}
