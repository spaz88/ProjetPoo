<?php

include 'Repertoire.php';

$root = new Repertoire('Root', 'd', 0);
$f1 = new Fichier('index', 'php', 1500);
$f2 = new Fichier('style', 'css', 250);

$media = new Repertoire('Media', 'd', 0);

$root->ajoutFichier($f1);
$root->ajoutFichier($f2);
$root->ajoutFichier($media);



$currentLoc = $root;

while(true) {
    printf("\n");
    printf("\n");
    printf("\n");

    printf("o_____ Bienvenue sur votre gestionnaire de fichiers _____o\n");
    printf("\n");

    printf("Vous êtes actuellement ici :" . $currentLoc->getNom() . " \n");
    printf("\n");

    printf("Que voulez-vous faire ? \n");
    printf("==> h (help) \n==> ls '(afficher les fichiers) \n==> mkdir (creer un repertoire) \n==> cd (déplacer avec les fichiers) \n==> touch (creer un fichier) \n exit (sortir)");

    // On commence l'algo
    $action = readline();

    while($action) {
        printf("\n");
        switch($action) {
            case "h":
                printf("==> h (help) \n==> ls '(afficher les fichiers) \n==> rm (supprime un dossier ou fichier) \n==> mkdir (creer un repertoire) \n==> cd (déplacer avec les fichiers) \n==> touch (creer un fichier) \n exit (sortir)");
                $action = null;
                break;
            
            case "ls":
                $currentLoc->listeFichier();
                $action = null;
                break;
    
            case "mkdir":
                printf("Choisissez un nom pour le répertoire :\n");
                $nom = readline();
                $tmp = new Repertoire($nom, 'd', 0);
                $currentLoc->ajoutFichier($tmp);
                $currentLoc->listeFichier();
                $action = null;
                break;
    
            case "touch":
                printf("Choissisez un nom pour votre fichier :\n");
                $nom = readline();
                printf("Choissisez une extension pour " . $nom."\n");
                $ext = readline();
                printf("Choississez une taille pour " . $nom . "." . $ext. "\n");
                $taille = intval(readline());
                $tmp2 = new Fichier($nom,$ext,$taille);
                $currentLoc->ajoutFichier($tmp2);
                $currentLoc->listeFichier();
                $action = null;
                break;
    
            case "cd":
                printf("Quel dossier voulez-vous rejoindre ?\n");
                $currentLoc->printDossier();
                printf("\n");
                $dir = readline();
                $currentLoc = $currentLoc->findDirectoryByName($dir);
                $currentLoc->listeFichier();
                $action = null;
                break;
            
            case "exit":
                exit();
                break;

            case "rm":
                printf("Quel fichier ou dossier voulez-vous supprimer ?\n");
                $currentLoc->printDossier();
                printf("\n");
                $bye = readline();
                $currentLoc->destroy($bye);
                $currentLoc->listeFichier();
                $action = null;
                break;
            
            default:
                $action = null;
                break;
        }
    }
    

}