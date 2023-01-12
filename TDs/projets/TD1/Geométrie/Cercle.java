package geometrie;

public class Cercle extends Ellipse{
    	
	protected String type;
	protected float rayon;

	public float getRayon(){
		return rayon;
	}

	public void setRayon(float rayon){
		this.rayon = rayon;
	}

	public void setType(String type){
		this.type = type;
	}
	
	public Cercle() {
		this.rayon = 0;
		this.type = "Cercle";
	}
	
	public Cercle(float rayon, String type){
		this.rayon = rayon;
		this.type = type;
	}

	public float calculAire(){
		return (float) (Math.PI*rayon*rayon);
	}
	
	public float calculPerimetre(){
		return (float) (2*Math.PI*rayon);
	}
	
	public String monType(){
		return type + "-->" + super.monType();
	}
}