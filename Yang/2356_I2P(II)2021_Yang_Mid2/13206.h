#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <sstream>

class BaseCodec {
public:
    virtual ~BaseCodec() {}
    virtual std::string encode(const std::string&) = 0;
};

class Reverse: public BaseCodec{
public:
    ~Reverse() {delete this;}
    std::string encode(const std::string& s1) {
        std::string s2 = "";
        for(int i = s1.length()-1; i >= 0; i--){
            s2.push_back(s1[i]);
        }
        return s2;
    }
};
class Compress: public BaseCodec{
public:
    ~Compress() {delete this;}
    std::string encode(const std::string& s1 ) {
        std::string s2 = "";
        std::stringstream ss;
        for(int i = 0, start = 0; i <= s1.length(); i++){
            if(s1[i] != s1[start] || i == s1.length()){
                if(i - start > 2) ss << i-start << s1[start];
                else ss << s1.substr(start, i-start);
                start = i;
            }
        }
        return ss.str();
    }
};
class Delay: public BaseCodec{
std::string delayStr;
public:
    Delay(){delayStr = "None";}
    ~Delay() {delete this;}
    std::string encode(const std::string& s1) {
        std::string s2 = delayStr;
        delayStr = s1;
        return s2;
    }
};

BaseCodec* getCodec(const std::string& name){
    BaseCodec *newCodec;
    if(name == "Reverse"){
        newCodec = new Reverse();
    }else if(name == "Compress"){
        newCodec = new Compress();
    }else{
        newCodec = new Delay();
    }
    return newCodec;
}

#endif

