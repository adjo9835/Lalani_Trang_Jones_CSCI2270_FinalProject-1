#include "QuizMe.h"
#include <iostream>
#include <fstream>
using namespace std;

QuizMe::QuizMe() {

    head = NULL;
    current = NULL;

}

QuizMe::~QuizMe() {


}

void QuizMe::buildSample() {

    string sampleKey = "What is the meaning of life?";
    string sampleDefinition = "42";

    FlashCard *card = new FlashCard;
    card -> key = sampleKey;
    card -> definition = sampleDefinition;
    card -> next = NULL;
    head = card;

}

void QuizMe::addCard(string key, string definition) {

    current = head;

    while(current -> next != NULL) {

        current = current -> next;

    }

    FlashCard *card = new FlashCard;
    card -> key = key;
    card -> definition = definition;
    card -> next = NULL;
    current -> next = card;
    card -> previous = current;

}

void QuizMe::printAll() {

    current = head;

    while(current != NULL) {

        cout << current -> key << " " << current -> definition << endl;
        current = current -> next;

    }

}

void QuizMe::uploadCards() {

    current = head -> next;

    ofstream file;
    file.open ("quizcards.txt");

    while(current != NULL) {

        file << current -> key;
        file << ",";
        file << current -> definition << "\n";
        current = current -> next;

    }

    file.close();

}
