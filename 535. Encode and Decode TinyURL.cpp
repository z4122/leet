535. Encode and Decode TinyURL


Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction
 on how your encode/decode algorithm should work. You just need to ensure that a 
 URL can be encoded to a tiny URL and the tiny URL can be decoded to the 
 original URL.



class Solution {
public:

    unordered_map<string,string> encodemap,decodemap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
         srand((unsigned int)time(NULL));
        string temp = "http://";
        for(int i = 0;i<7;i++)
        {
           temp += longUrl[std::rand()%longUrl.size()];
        }
        encodemap[longUrl] = temp;
        decodemap[temp] = longUrl;
        return temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodemap[shortUrl];
    }
};