#include<bits/stdc++.h>
#include <fstream>
using namespace std;
 
#define int long long
#define ln '\n'
#define very_long 1000000007
int min(vector<int>& a)
{
  int mini = LLONG_MIN;
  for(int i=0; i<a.size(); i++) mini = mini<a[i]?mini:a[i];
  return mini;
}

const int ALPHABET_SIZE = 26;


vector<int> getseq(int n)
{
    vector<int> orig(n);
    for(int i=0; i<n; i++) orig[i] = i;
    vector<int> temp = orig;
    vector<int> ans;

    while(temp.size())
    {
        int s = temp.size();
        srand(time(NULL));
        int index = rand() % s;
        int random_number = temp[index];
        ans.push_back(random_number);
        swap(temp[index],temp[s-1]);
        temp.pop_back();
    }

    return ans;

}

// trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}

string getRandom(struct TrieNode *root)
{
    string word="heheh";
    struct TrieNode *it=root;
    for(int i=0; i<5; i++)
    {
        vector<int> seq = getseq(26);
        for(int j=0; j<26; j++)
        {
            if(it->children[seq[j]])
            {
                word[i] = 'a'+seq[j];
                it = it->children[seq[j]];
                break;
            }
        }
    }
    return word;
}

void solve() {
    

    struct TrieNode *root = getNode();
    
    //input all words

    fstream newfile;
    newfile.open("words.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            insert(root,tp); //print the data of the string
        }
        newfile.close(); //close the file object.
    }

    string answer = getRandom(root);
    // cout<<answer<<ln;
    // return;
    for(int i=0; i<6;)
    {
        cout<<i+1<<"/6. Enter a 5 letter word, bitch!"<<ln;
        string test_word;
        cin>>test_word;
        if(test_word.length()!=5)
        {
            cout<<"Wasn't a 5 letter word, bitch!"<<ln;
            continue;
        }
        if(!search(root,test_word))
        {
            cout<<"Your gibberish ain't a word, bitch!"<<ln;
            continue;
        }
        if(test_word==answer)
        {
            cout<<"Congrats bitch! You fucking won"<<ln;
            break;
        }
        
        map<char,int> m;
        for(int j=0; j<5; j++) m[answer[j]]++;
        string output;
        for(int j=0; j<5; j++)
        {
            output.push_back(test_word[j]);
            if(m[test_word[j]])
            {
                if(m[test_word[j]]==1) m.erase(test_word[j]);
                else m[test_word[j]]--;
                if(test_word[j]==answer[j])
                output = output + "G ";
                else output = output + "Y ";
            }
            else output = output + "X ";
        }
        cout<<output<<ln;
        if(i==5)
        cout<<"Lmao noob, the correct word was "<<answer<<ln;
        i++;
    }

}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();

}