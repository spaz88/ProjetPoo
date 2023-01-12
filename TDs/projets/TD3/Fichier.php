<?php

class Fichier {

    // Variables et constructeur 
    protected $nom;
    protected $extension;
    protected $taille;

    public function __construct($nom,$extension,$taille) {
        $this->nom = $nom;
        $this->extension = $extension;
        $this->taille = $taille;
    }

    public function __desctruct() { }


    // Getters & Setters
    public function getNom() : string {
        return $this->nom;
    }

    public function getExtension() : string {
        return $this->extension;
    }

    public function getTaille() {
        return $this->taille;
    }

    public function setNom($nom) : void {
        $this->nom = $nom;
    }

    public function setTaille($taille) : void {
        $this->taille = $taille;
    }

    public function setExtension($extension) : void {
        $this->extension = $extension;
    }



}