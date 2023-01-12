package geometrie;

public class Geometrie{
    
    protected String type;
    
    public void setType(String type){
        this.type = type;
    }
    
    public void Geometrie(String type){
        this.type = "Géometrie";
    }
    
     public float calculAire(){
        return 0;
    }
     public float calculPerimetre(){
        return 0;
    }
     public String monType(){
        return type;
    }
}