<?php

class Card {

    private string $rank;
    private string $suit;

    public function __construct($rank, $suit) {
        $this->rank = $rank;
        $this->suit = $suit;
    }

    public function getRank() : string {
        return $this->rank;
    }

    public function getSuit() : string {
        return $this->suit;
    }

    public function setRank(string $rank) : void {
        $this->rank = $rank;
    }

    public function setSuit(string $suit) : void {
        $this->suit = $suit;
    }

    public function display() : void {
        echo "Card : Rank - " . $this->rank . " Suit : " . $this->suit;
    }

}