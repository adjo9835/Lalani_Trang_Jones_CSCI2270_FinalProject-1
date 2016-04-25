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

void *QuizMe::findCard(string key){
    FlashCard *ptr = head;
    bool found = false;
    while (ptr != NULL){
        if (ptr->key==key){
            cout << "Back of card: " << endl;
            cout << ptr->definition << endl;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found){
        cout << "Card not found" << endl;
    }
}

void QuizMe::editCard(string key,string newkey, string newdef){
    //deleteCard(key);
    addCard(newkey,newdef);
}

void QuizMe::total(){
    int counter = 0;
    FlashCard *ptr = head;
    while (ptr != NULL){
        counter++;
        ptr=ptr->next;
    }
    cout << "Total number of cards: " << counter << endl;
}
