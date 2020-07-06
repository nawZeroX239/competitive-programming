
inline void split(vector<string>& vect, string& str, char delim) {
    string each;
    for (auto it = str.begin(); it != str.end(); ++it)
        if (*it != delim) {
            each.push_back(*it);
        } else {
            vect.push_back(each);
            each.clear();
        }

    if (each.size())
        vect.push_back(each);
}
