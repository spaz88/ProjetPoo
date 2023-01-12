<?php

include 'Fichier.php';

class Repertoire extends Fichier {

    private $contenu;

    public function __construct($nom,$extension, $taille) {
        parent::__construct($nom,$extension,$taille);
        $this->contenu = array();
    }

    public function __desctruct() { }

    // Push fichier puis MAJ taille
    public function ajoutFichier(Fichier $f) : void {
        array_push($this->contenu, $f);
        $this->setTaille(intval($this->getTaille()) + intval($f->getTaille()));
    }

    // On liste tous les fichiers en séparant les éléments 
    public function listeFichier() : void {
        printf("Dans le répertoire : " . $this->nom . " de taille : " . $this->getTaille() ."\n");

        foreach($this->contenu as $fichier) {
            if($fichier->getExtension() != "d") {
                printf("-> " . $fichier->getNom().".".$fichier->getExtension() . "    " . $fichier->getTaille());
                printf("\n");
            } else {
                printf(">> " . $fichier->getNom() . "        Dossier de taille : " . $fichier->getTaille());
                printf("\n");
            }
            
        }
    }

    // On affiche uniquement les dossiers présents 
    public function printDossier() : void {
        foreach($this->contenu as $fichier) {
            if($fichier->getExtension() == "d") {
                printf(">> " . $fichier->getNom() . "        Dossier de taille : " . $fichier->getTaille()."\n");
            }
            
        }
    }

    // On essaye de trouver un répertoire grâce au nom pour sortir un objet
    public function findDirectoryByName($name) {
        foreach($this->contenu as $rep) {
            if($rep->getNom() == $name) {
                return $rep;
            }
        } 
        printf("Aucun repertoire de ce nom trouvé");
    }

    // On détruit un élément donné 
    public function destroy($name) {
        $find_one = array_search($name, $this->contenu , true);
        if($find_one) {
            unset($this->contenu[$find_one]);
        }
    }







}