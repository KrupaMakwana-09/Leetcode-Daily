bool isIsomorphic(char* s, char* t) {
    int mapST[256] = {0};
    int mapTS[256] = {0};

    for (int i = 0; s[i] && t[i]; i++) {
        unsigned char sc = s[i];
        unsigned char tc = t[i];

        if (mapST[sc] == 0 && mapTS[tc] == 0) {
            mapST[sc] = tc;
            mapTS[tc] = sc;
        } else if (mapST[sc] != tc || mapTS[tc] != sc) {
            return false;
        }
    }

    return s[strlen(s)] == t[strlen(t)];
}