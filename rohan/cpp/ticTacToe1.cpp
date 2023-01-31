#include <iostream>

using namespace std;
// Class to store player scores

class Player
{
private:
    string name;
    int score; // Overall performance in numerical form
    int rank;  // To be displayed in leaderboard along with score
    // int playx=0,playO=0; //count no of times played as X and O
    // player prev,next; /*for doubly link list traversal/
    static int pcount;
    int winnum, matches;
    float winrate;
    Player *next;
    static Player *first;

public:
    Player()
    {
        pcount++;
        score = 0;
        winnum = 0;
        matches = 0;
        rank = pcount;
    }
    static Player *getPlayer(string playname)
    {
        Player *temp = first;
        while (temp != NULL)
        {
            if (temp->name == playname)
                return temp;
        }
    }
    static int search(string playname)
    {
        if (first == NULL)
            return 0;

        Player *temp = first;
        while (temp != NULL)
        {
            if (temp->name == playname)
                return 1;
            temp = temp->next;
        }
        return 0;
    }
    static Player *setProfile(char play)
    {
        int choice;
        string playname;
        while (1)
        {
            cout << "Player " << play << ":" << endl;
            cout << "Create an account or login?\nLogin(2),Create(1), Guest(0):";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter your name:";
                cin >> playname;
                if (first == NULL)
                {
                    first = new Player;
                    first->name = playname;
                    first->next = NULL;
                    cout << "Account created" << endl;
                    return first;
                }
                if (search(playname))
                {
                    cout << search(playname) << endl;
                    cout << "Account already exists.\nTry another name,logging in or proceed without account" << endl;
                }
                else
                {
                    Player *temp = new Player;
                    temp->name = playname;
                    temp->next = NULL;
                    // Insert player "node" at end of list
                    Player *trav = first;
                    while (trav->next != NULL)
                    {
                        trav = trav->next;
                    }
                    trav->next = temp;
                    cout << "Account created" << endl;
                    return temp;
                }
            }
            else if (choice == 2)
            {
                cout << "Enter account name:";
                cin >> playname;
                if (search(playname))
                {
                    Player *temp = getPlayer(playname);
                    cout << "Logged in\n";
                    return temp;
                }
                else
                    cout << "Account not found.\nCreate a new one,retry logging in or proceed" << endl;
            }
            else if (choice == 0)
            {
                cout << "Playing as guest" << endl;
                return NULL;
            }
        }
    }

    static void modifyScore(int movecount, char win, Player *p1, Player *p2)
    {

        if (win == 'X')
        {
            if (p1 != NULL)
                p1->winnum++;
            if (movecount == 9)
            {
                if (p1 != NULL)
                    p1->score += 50;
                if (p2 != NULL)
                {
                    p2->score -= 10;
                    if (p2->score < 0)
                        p2->score = 0;
                }
            }
            if (movecount == 7)
            {
                if (p1 != NULL)
                    p1->score += 75;
                if (p2 != NULL)
                {
                    p2->score -= 30;
                    if (p2->score < 0)
                        p2->score = 0;
                }
            }
            if (movecount == 5)
            {
                if (p1 != NULL)
                    p1->score += 100;
                if (p2 != NULL)
                {
                    p2->score -= 50;
                    if (p2->score < 0)
                        p2->score = 0;
                }
            }
        }
        else if (win == 'O')
        {
            if (p2 != NULL)
                p2->winnum++;
            if (movecount == 8)
            {
                if (p2 != NULL)
                    p2->score += 75;
                if (p1 != NULL)
                {
                    p1->score -= 30;
                    if (p1->score < 0)
                        p1->score = 0;
                }
            }
            if (movecount == 6)
            {
                if (p2 != NULL)
                    p2->score += 100;
                if (p1 != NULL)
                {
                    p1->score -= 50;
                    if (p1->score < 0)
                        p1->score = 0;
                }
            }
        }
        else
        {
            p2->score++;
        }
        if (p1 != NULL)
        {
            p1->matches++;
            p1->winrate = p1->winnum / p1->matches;
        }

        if (p2 != NULL)
        {
            p2->matches++;
            p2->winrate = p2->winnum / p2->matches;
        }
        Player::calcrank();
        Player::playersort();
    }
    static void calcrank()
    {
        // First set all ranks back to playercount for recalculation
        // Then decrement each time there's a better score found vs selected player, for all players
        Player *tempi;
        Player *tempj;
        for (tempi = first; tempi != NULL; tempi = tempi->next)
        {
            tempi->rank = pcount;
        }
        for (tempi = first; tempi != NULL; tempi = tempi->next)
        {
            for (tempj = first; tempj != NULL; tempj = tempj->next)
            {
                if (tempi->score > tempj->score)
                    tempi->rank--;
            }
        }
    }
    static void playersort()
    {
        Player *tempi;
        Player *tempj;
        for (tempi = first; tempi != NULL; tempi = tempi->next)
        {
            for (tempj = tempi; tempj != NULL; tempj = tempj->next)
            {
                if (tempi->rank > tempj->rank)
                {
                    // Save previous and next of nodes to be swapped
                    Player *iprev, *inext, *jprev, *jnext = first;
                    iprev = inext = jprev = jnext;
                    while (iprev->next != tempi)
                    {
                        iprev = iprev->next;
                    }
                    while (jprev->next != tempj)
                    {
                        jprev = jprev->next;
                    }
                    // Perform swapping
                    inext = iprev->next->next;
                    jnext = jprev->next->next;
                    tempi->next = jnext;
                    jprev->next = tempi;
                    tempj->next = inext;
                    iprev->next = tempj;
                }
            }
        }
    }
    static void dispLeader()
    {
        Player *temp = first;
        cout << "\n\t\t\t\tLeaderboard:" << endl;
        cout << "Rank\tName\t\tScore\tMatches\tWinrate" << endl;
        for (int i = 0; i < pcount; i++)
        {
            cout << temp->rank << "\t" << temp->name << "\t\t" << temp->score << "\t" << temp->matches << "\t" << temp->winrate * 100 << "%" << endl;
            temp = temp->next;
        }
    }
    static Player *getFirst()
    {
        return first;
    }
};

int Player::pcount = 0; // Tracking number of player objects
Player *Player::first = NULL;
char board[3][3]; // Array to store moves
int i, j, m, n;   // count to end draw case
void game(Player *, Player *);
void display(); // function to display board
// void leader(); //function to display leaderboard
void rules(); // function to display rules
char wincheck(int movecount);

int main()
{
    int choice; // For menu

    while (1)
    {
        // Repeating menu
        cout << "\n\t\t\t\tMenu\n\t\t\t\t1.Start\n\t\t\t\t2.Check leaderboard\n\t\t\t\t3.Check rules\n\t\t\t\t4.Exit\nEnter your choice:";
        cin >> choice; // Taking user choice

        switch (choice)
        {
        case 1:
        {
            Player *p1 = Player::setProfile('X');
            Player *p2 = Player::setProfile('O');
            game(p1, p2);
            break;
        }
        case 2:
        {
            Player *check = Player::getFirst();
            if (check != NULL)
                Player::dispLeader();
            else
                cout << "Leaderboard is empty\n";
            break;
        }
        case 3:
        {
            rules();
            break;
        }
        case 4:
        {
            printf("Successfully exited\n");
            exit(0);
        }
        }
    }
    return 0;
}

void display()
{

    // Display board
    // Make this a function, some variables to be made global
    cout << " _ _ _\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << "|" << board[i][j] << "";
        }
        cout << "|\n _ _ _ \n";
    }
}

void game(Player *p1, Player *p2)
{
    char win = ' '; // To declare winner
    char move;      // To determine the next move without repeating check code
    int movecount = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
    move = 'X';
    // Start message

    cout << "\t\t\t\tTic tac toe\n\t\t\t\tBoard:\n\n";
    display();

    // Input by X
    while (win == ' ')
    {
        cout << move << " turn:\nEnter the position(1 to 3, 1 to 3):";
        cin >> m >> n;
        // Check
        if (m > 0 && m < 4 && n > 0 && n < 4 && board[m - 1][n - 1] == ' ')
        {
            board[m - 1][n - 1] = move;
            movecount++;
            display();
            win = wincheck(movecount);
            if (move == 'X')
            {
                move = 'O';
            }
            else
            {
                move = 'X';
            }
        }
        else
        {
            cout << "Invalid input, try again";
        }
    }
    Player::modifyScore(movecount, win, p1, p2);
}

char wincheck(int movecount)
{
    char win = ' ';
    for (i = 0; i < 3; i++)
    {
        // Row check
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if (board[i][0] != ' ')
            {
                win = board[i][0];
                cout << "\n"
                     << win << " wins";
                return win;
            }
        }
    }
    for (j = 0; j < 3; j++)
    {
        // Column check
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            if (board[0][j] != ' ')
            {
                win = board[0][j];
                cout << "\n"
                     << win << " wins";
                return win;
            }
        }
    }
    // Diagonal check
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        if (board[0][0] != ' ')
        {
            win = board[0][0];
            cout << "\n"
                 << win << " wins";
            return win;
        }
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        if (board[0][2] != ' ')
        {
            win = board[0][2];
            cout << "\n"
                 << win << " wins";
            return win;
        }
    }
    if (movecount == 9)
    {
        cout << "\nDraw";
        win = 'D';
        return win;
    }
    return win;
}
void rules()
{
    cout << "Rules:\n1. The first turn is given to player X\n2. Each player get one turn at a time\n3. A player wins if 3 of their respective symbol are in a horizontal, vertical or diagonal line\n4. If no player manages to win and the board is filled(9 moves) the game is considered as a draw\n";
}