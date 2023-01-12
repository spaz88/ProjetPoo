<?php

// Class mère 
class CEmploye {


    // Base variable & constructeur 
    protected string $m_nom;
    protected string $m_prenom;
    protected int $m_age;
    protected int $m_anciennete;

    public function __construct($nom,$prenom,$age, $anc) {
        $this->m_nom = $nom;
        $this->m_prenom = $prenom;
        $this->m_age = $age;
        $this->m_anciennete = $anc;
    }

    public function __destruct() { }

    // Base Getter & Setters 

    public function employe() : void {
        echo "Nom : " . $this->getNom() . " Prénom : " . $this->getPrenom() . " age : " . $this->getAge() . " ancienneté : " . $this->getAnciennete();
    }

    public function getNom() {
        return $this->m_nom;
    }

    public function setNom($nom) {
        $this->m_nom = $nom;
    }

    public function getPrenom() {
        return $this->m_prenom;
    }

    public function setPrenom($prenom) {
        $this->m_prenom = $prenom;
    }

    public function getAge() {
        return $this->m_age;
    }

    public function setAge($age) {
        $this->m_age = $age;
    }

    public function getAnciennete() {
        return $this->m_anciennete;
    }

    public function setAnciennete($anciennete) {
        $this->m_anciennete = $anciennete;
    }


    // Méthodes spéciales 

    
    public function calculBaseSalaire() {
        
    }

    // Méthode finale utilisant une méthode qui sera redéfinie
    public function calculSalaire() : float {
        return $this->calculBaseSalaire() + ($this->calculBaseSalaire() * $this->m_anciennete * 0.05);
    }
}