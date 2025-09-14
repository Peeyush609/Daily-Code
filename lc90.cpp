class Solution {
public:
    // helper: replace all vowels with '*'
    string devowel(string s) {
        for (char &c : s) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                c = '*';
            } else {
                c = lower; // normalize to lowercase
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        // Preprocessing
        for (string &w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!caseInsensitive.count(lower)) caseInsensitive[lower] = w;
            
            string dev = devowel(w);
            if (!vowelInsensitive.count(dev)) vowelInsensitive[dev] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) { // exact match
                ans.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (caseInsensitive.count(lower)) { // case-insensitive match
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            string dev = devowel(q);
            if (vowelInsensitive.count(dev)) { // vowel error match
                ans.push_back(vowelInsensitive[dev]);
                continue;
            }

            ans.push_back(""); // no match
        }
        return ans;
    }
};
