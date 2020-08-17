#include "printDialog.h"

int main() {
    std::string name = "M'aiq the Liar";
    std::string sentence = "M'aiq’s father was also called M'aiq. As was M'aiq’s father’s father. At least, that iswhat his father said.";
    // std::string sentence = "M'aiq's father was also called M'aiq. As was M'aiq's father's father. At least,thatis whathis fathersaid.";

    printDialog(name, sentence);
}