package geometrie;

import java.util.ArrayList;

public class Polygone extends Geometrie{
    
    protected String type;
	protected ArrayList<Float> longueurCotes;

	public ArrayList<Float> getLongueurCotes() {
		return longueurCotes;
	}
	
	public void setLongueurCotes(ArrayList<Float>longueurCotes){
	    this.longueurCotes = longueurCotes;
	}
	
	public setType(String type){
	    this.type = type;
	}
	
	public Polygone(){
	    this.longueurCotes = new ArrayList<Float>();
	    this.type = "Polygone";
	}
	
		public Polygone(ArrayList<Float>longueurCotes, String type){
	    this.longueurCotes = longueurCotes;
	    this.type = type;
	}
	
	public float calculAire(){
	    return 0;
	}
	
	public float calculPerimetre(){
	    float perimetre=0;
	    for(int i=0; i<longueurCotes.size(); i++){
	        perimettre += longueurCotes.get(i);
	    }
	    return perimetre;
	}
	
	public String monType(){
	    return type + "-->" + super.monType;
	}
}