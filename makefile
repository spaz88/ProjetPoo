all: objectBattlers objectDeck objectGame objectPlayer
	g++ -g -o ProjetPooJeux ProjetPooJeux.cpp objectBattlers.o objectDeck.o objectGame.o objectPlayer.o

objectDeck:
	g++ -c -Wall -g -fpic Deck.cpp -o objectDeck.o
objectPlayer:
	g++ -c -Wall -g -fpic Player.cpp -o objectPlayer.o
objectBattlers:
	g++ -c -Wall -g -fpic Battlers.cpp -o objectBattlers.o
objectGame:
	g++ -c -Wall -g -fpic Game.cpp -o objectGame.o