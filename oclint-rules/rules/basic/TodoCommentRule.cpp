#include "oclint/AbstractSourceCodeReaderRule.h"
#include "oclint/RuleConfiguration.h"
#include "oclint/RuleSet.h"
#include "oclint/util/StdUtil.h"

using namespace std;
using namespace oclint;

class TodoCommentRule : public AbstractSourceCodeReaderRule {
public:
    virtual const string name() const override {
        return "todo comment";
    }

    virtual int priority() const override {
        return 3;
    }

    virtual void eachLine(int lineNumber, string line) override {
        size_t pos = line.find("TODO");
        if (pos != string::npos) {
            addViolation(lineNumber, pos, lineNumber, pos + 4, this, "");
        }
    }
};

static RuleSet rules(new TodoCommentRule());
