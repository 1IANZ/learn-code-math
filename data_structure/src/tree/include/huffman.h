
#include <string>

struct HuffNode {
    char ch;
    int freq;
    HuffNode* left;
    HuffNode* right;

    HuffNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    HuffNode(int f, HuffNode* l, HuffNode* r) : ch('\0'), freq(f), left(l), right(r) {}
};
class HuffmanTree {
  private:
    HuffNode* root;
    std::string codes[256];
    void destroy(HuffNode* node);
    void generateCodes(HuffNode* node, const std::string& prefix);

  public:
    HuffmanTree();
    ~HuffmanTree();

    void build(const std::string& text);

    std::string* getCodesArray();
    static void test();
};
