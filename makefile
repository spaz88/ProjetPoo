all: objectBattlers objectDeck objectGame objectPlayer
	g++ -o ProjetPooJeux ProjetPooJeux.cpp objectBattlers.o objectDeck.o objectGame.o objectPlayer.o

objectDeck:
	g++ -c -Wall -Werror -fpic Deck.cpp -o Deck.o
objectPlayer:
	g++ -c -Wall -Werror -fpic Player.cpp -o Player.o
objectBattlers:
	g++ -c -Wall -Werror -fpic Battlers.cpp -o Battlers.o
objectGame:
	g++ -c -Wall -Werror -fpic Game.cpp -o Game.o