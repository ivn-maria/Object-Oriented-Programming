#include "Book.h"

void Book::addRating(unsigned short r, const string& name)
{
    if (r > 10)
        return;

    size_t raterIndex = -1;

    for (size_t i = 0; i < ratings.size(); i++)
    {
        if (name == ratings[i].first)
        {
            raterIndex = i;
            break;
        }
    }

    if (raterIndex != -1)
        ratings[raterIndex].second = r;
    else {
        pair<string, unsigned> toPush(name, r);
        ratings.push_back(std::move(toPush));
    }
}

void Book::write(unsigned pagesCount)
{
    unsigned short lines = 0;

    for (int i = 0; i < pagesCount; i++)
    {
        std::cout << "Enter lines in page " << i + 1 << ": ";
        std::cin >> lines;
        std::cin.ignore();
        Page toInsert;

        toInsert.write(lines);

        data.push_back(std::move(toInsert));
    }
}

void Book::displayBook() const
{
    bool reading = true;
    bool displayMenu = true;
    unsigned pageNumber = 0;

    char cmd = '\0';
    unsigned pageIndex = 0;

    while (reading)
    {
        system("cls");
        if (displayMenu)
            displayHelpMenu();

        data[pageIndex].displayPage();

        std::cin.get(cmd);

        switch (cmd) {
            case 'n':
                if (pageIndex < data.size() - 1)
                    pageIndex++;
                break;
            case 'p':
                if (pageIndex > 0)
                    pageIndex--;
                break;
            case 'h':
                displayMenu = !displayMenu;
                break;
            case 'q':
                reading = false;
                break;
            case '@':
                std::cin >> pageNumber;
                if (pageNumber >= 1 && pageNumber < data.size() + 1)
                    pageIndex = pageNumber - 1;
                break;
            default:
                break;
        }
    }
    system("cls");
}

void Book::showComments() const
{
    for (const auto & comment : comments)
        std::cout << comment.first << " wrote: " << comment.second << std::endl;
}

void Book::showRates() const
{
    for (const auto & rating : ratings)
        std::cout << rating.first << ": " << rating.second << " start" << std::endl;
    std::cout << std::endl;

    std::cout << "Avarage rate: " << getAverageRating() << std::endl;
}

void Book::print() const
{
    std::cout << title << " by: " << author << std::endl;
}

void Book::displayHelpMenu()
{
    std::cout << "Entered reader mode." << std::endl
              << "Press n for next, p for prev." << std::endl <<
              "Press @ + <number> to go to that page" << std::endl <<
              "Press h to hide or show this menu or q to exit" << std::endl;
}

Book::Book(const string& pAuthor, const string& pTitle)
{
    author = pAuthor;
    title = pTitle;
}

void Book::writeToFile(std::ofstream& outFile) const
{
    writeString(outFile, author);
    writeString(outFile, title);

    size_t len = data.size();
    outFile.write((const char*)&len, sizeof(len));
    for (size_t i = 0; i < len; i++)
        data[i].writeToFile(outFile);

    size_t commentsLen = comments.size();
    outFile.write((const char*)&commentsLen, sizeof(commentsLen));
    for (size_t i = 0; i < commentsLen; i++)
        writeCommentsToFile(outFile, comments[i]);

    size_t ratesCount = this->ratings.size();
    outFile.write((const char*)&ratesCount, sizeof(ratesCount));
    for (size_t i = 0; i < ratesCount; i++)
        writeRatesToFile(outFile, ratings[i]);
}

void Book::readFromFile(std::ifstream& inFile)
{
    author = readString(inFile);
    title = readString(inFile);


    int len = 0;
    inFile.read((char*)&len, sizeof(len));
    for (size_t i = 0; i < len; i++)
    {
        data.emplace_back();
        data[i].readFromFile(inFile);
    }

    int commentsLen = 0;
    inFile.read((char*)&commentsLen, sizeof(commentsLen));
    for (size_t i = 0; i < commentsLen; i++)
    {
        pair<string, string> toInsert = readCommentsFromFile(inFile);
        comments.push_back(std::move(toInsert));
    }

    int ratesCount = 0;
    inFile.read((char*)&ratesCount, sizeof(ratesCount));
    for (size_t i = 0; i < ratesCount; i++)
    {
        pair<string, unsigned> toPush = readRatesFromFile(inFile);
        ratings.push_back(std::move(toPush));
    }
}

double Book::getAverageRating() const
{
    double sum = 0;
    for (const auto & rating : ratings)
        sum += rating.second;

    return sum / (double)(ratings.size());
}