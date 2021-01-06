#include <iostream>

enum class Suits
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};

enum class CardNames
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
};

struct Card
{
    CardNames name;
    Suits suit;
    int value;

    void PrintCard()
    {
        PrintValue();

        std::cout << " of ";

        PrintSuit();

        std::cout << std::endl;
    }

    void PrintValue()
    {
        if (name == CardNames::JACK)
        {
            std::cout << "jack";
        }
        else if (name == CardNames::QUEEN)
        {
            std::cout << "queen";
        }
        else if (name == CardNames::KING)
        {
            std::cout << "king";
        }
        else if (name == CardNames::ACE)
        {
            std::cout << "ace";
        }
        else
        {
            std::cout << value;
        }
    }

    void PrintSuit()
    {
        if (suit == Suits::CLUBS)
        {
            std::cout << "clubs";
        }
        else if (suit == Suits::DIAMONDS)
        {
            std::cout << "diamonds";
        }
        else if (suit == Suits::HEARTS)
        {
            std::cout << "hearts";
        }
        else if (suit == Suits::SPADES)
        {
            std::cout << "spades";
        }
    }
};

struct Deck
{
    Card arrCards[52];

    void PrintAll()
    {
        for (int col = (int)Suits::CLUBS; col <= (int)Suits::SPADES; col++)
        {
            for (int row = (int)CardNames::ACE; row <= (int)CardNames::KING; row++)
            {
                int index = (13 * col) + row - 1;

                arrCards[index].PrintCard();
            }

            std::cout << std::endl;
        }
    }

    void SetupCards()
    {
        for (int col = (int)Suits::CLUBS; col <= (int)Suits::SPADES; col++)
        {
            for (int row = (int)CardNames::ACE; row <= (int)CardNames::KING; row++)
            {
                Card c;
                c.suit = (Suits)col;
                c.name = (CardNames)row;

                if (c.name == CardNames::JACK)
                {
                    c.value = 10;
                }
                else if (c.name == CardNames::QUEEN)
                {
                    c.value = 10;
                }
                else if (c.name == CardNames::KING)
                {
                    c.value = 10;
                }
                else
                {
                    c.value = (int)c.name;
                }

                std::cout << (int)c.name << " of " << (int)c.suit << std::endl;
                
                int index = (13 * col) + row - 1;
                
                arrCards[index] = c;
            }
        }
    }
};

int main()
{
    Deck deck;
    deck.SetupCards();

    std::cout << std::endl;

    deck.PrintAll();
}