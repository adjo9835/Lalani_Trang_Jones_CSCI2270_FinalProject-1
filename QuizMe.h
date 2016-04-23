#ifndef QUIZME_H
#define QUIZME_H
#include <iostream>
#include <vector>

struct FlashCard {
    
    std::string key;
    std::string definition;

struct FlashCard{
    string key;
    string definition;
    FlashCard *next;
    FlashCard *previous;

};

class QuizMe {

    public:
        QuizMe();
        ~QuizMe();
        void buildSample();
        void addCard(std::string key, std::string definition);
        void findCard(std::string key, std::string definition);
        void deleteCard(std::string key);
        void printAll();
        void deleteAll();
        void editCard(std::string key);
        void uploadCards(std::string fileName);
        void quiz();

    protected:

    private:
        FlashCard *head;
        FlashCard *current;

class QuizMe
{
    public:
        QuizMe();
        ~QuizMe();
        void addCard(string key);
        void findCard(string key, string definition);
        void deleteCard(string key);
        void printAll();
        void deleteAll();
        void editCard(string key);
        void uploadCards(string fileName);
        void quiz();

    protected:
    private:
        FlashCard *head;
        Flashcard *tail;

};

#endif // QUIZME_H
