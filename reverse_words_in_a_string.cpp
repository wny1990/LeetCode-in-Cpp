class Solution {
public:
void reverseWords(string &s) {
    string s1,subs,subs_rev;
	unsigned start_p,end_p;
    bool in_word = false;
    for(unsigned i = 0; i < s.length(); ++i)
    {
	    if (s.at(i) != ' ' && in_word == false )
	   	{
     		in_word = true;
			start_p = i;
		}
		if (( s.at(i) == ' ' || i == s.length() - 1 ) && in_word == true )
        {
    		in_word = false;
			end_p = i;
			if (i == s.length() - 1 && s.at(i)!=' ' ) end_p = i + 1;
		    subs = s.substr(start_p, end_p - start_p );
		    subs_rev.clear();
			for(int j = subs.length() - 1; j >= 0; --j)
                 subs_rev.push_back(subs.at(j));
			if (s1.length() != 0 ) s1.push_back(' ');
		    s1.append(subs_rev);
		}
	}
	s.clear();
	if (s1.length() == 0) return;
    for(int i = s1.length() - 1; i >= 0; --i)
        s.push_back(s1.at(i));
    return;
}	
};
