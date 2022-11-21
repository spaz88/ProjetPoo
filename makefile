all: objectBattlers objectDeck objectGame objectPlayer
	g++ -o ProjetPooJeux ProjetPooJeux.cpp objectBattlers.o objectDeck.o objectGame.o objectPlayer.o

objectDeck:
	g++ -c -Wall -Werror -fpic Deck.cpp -o objectDeck.o
objectPlayer:
	g++ -c -Wall -Werror -fpic Player.cpp -o objectPlayer.o
objectBattlers:
	g++ -c -Wall -Werror -fpic Battlers.cpp -o objectBattlers.o
objectGame:
	g++ -c -Wall -Werror -fpic Game.cpp -o objectGame.o