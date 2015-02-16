#include "oclint/AbstractSourceCodeReaderRule.h"
#include "oclint/RuleConfiguration.h"
#include "oclint/RuleSet.h"
#include "oclint/util/StdUtil.h"

using namespace std;
using namespace oclint;

class NoSonarCommentRule : public AbstractSourceCodeReaderRule {
public:
    virtual const string name() const override {
        return "nosonar comment";
    }

    virtual int priority() const override {
        return 3;
    }

    virtual void eachLine(int lineNumber, string line) override {
        size_t pos = line.find("NOSONAR");
        if (pos != string::npos) {
            addViolation(lineNumber, pos, lineNumber, pos + 7, this, "");
        }
    }
};

static RuleSet rules(new NoSonarCommentRule());
