#include <iostream>
#include <memory>
#include <string>

using namespace std;

// ---------- Common product interface ----------
class IEvaluator {
public:
    virtual void evaluate(const string& response) const = 0;
    virtual ~IEvaluator() = default;
};

// ---------- GATE library ----------
namespace gate_lib {
    class GATE_mcq_eval : public IEvaluator {
    public:
        void evaluate(const string& r) const override {
            cout << "Evaluated " << r << " as per GATE MCQ question.\n";
        }
    };
    class GATE_fillin_eval : public IEvaluator {
    public:
        void evaluate(const string& r) const override {
            cout << "Evaluated " << r << " as per GATE Fillin question.\n";
        }
    };
    class GATE_essay_eval : public IEvaluator {
    public:
        void evaluate(const string& r) const override {
            cout << "Evaluated " << r << " as per GATE Essay question.\n";
        }
    };
    class GATE_truefalse_eval : public IEvaluator {
    public:
        void evaluate(const string& r) const override {
            cout << "Evaluated " << r << " as per GATE T/F question.\n";
        }
    };
}

// ---------- JEE library ----------
namespace jee_lib {
    class JEE_mcq_eval : public IEvaluator {
    public:
        void evaluate(const string& r) const override {
            cout << "Evaluated " << r << " as per JEE Main MCQ question.\n";
        }
    };
    class JEE_fillin_eval : public IEvaluator {
    public:
        void evaluate(const string& r) const override {
            cout << "Evaluated " << r << " as per JEE Main Fillin question.\n";
        }
    };
    class JEE_essay_eval : public IEvaluator {
    public:
        void evaluate(const string& r) const override {
            cout << "Evaluated " << r << " as per JEE Main Essay question.\n";
        }
    };
    class JEE_truefalse_eval : public IEvaluator {
    public:
        void evaluate(const string& r) const override {
            cout << "Evaluated " << r << " as per JEE Main T/F question.\n";
        }
    };
}

// ---------- Abstract Factory ----------
class ExamFactory {
public:
    virtual unique_ptr<IEvaluator> createMcq() const = 0;
    virtual unique_ptr<IEvaluator> createFillin() const = 0;
    virtual unique_ptr<IEvaluator> createEssay() const = 0;
    virtual unique_ptr<IEvaluator> createTrueFalse() const = 0;
    virtual ~ExamFactory() = default;
};

// ---------- Concrete Factories ----------
class GateExamFactory : public ExamFactory {
public:
    unique_ptr<IEvaluator> createMcq() const override {
        return make_unique<gate_lib::GATE_mcq_eval>();
    }
    unique_ptr<IEvaluator> createFillin() const override {
        return make_unique<gate_lib::GATE_fillin_eval>();
    }
    unique_ptr<IEvaluator> createEssay() const override {
        return make_unique<gate_lib::GATE_essay_eval>();
    }
    unique_ptr<IEvaluator> createTrueFalse() const override {
        return make_unique<gate_lib::GATE_truefalse_eval>();
    }
};

class JeeExamFactory : public ExamFactory {
public:
    unique_ptr<IEvaluator> createMcq() const override {
        return make_unique<jee_lib::JEE_mcq_eval>();
    }
    unique_ptr<IEvaluator> createFillin() const override {
        return make_unique<jee_lib::JEE_fillin_eval>();
    }
    unique_ptr<IEvaluator> createEssay() const override {
        return make_unique<jee_lib::JEE_essay_eval>();
    }
    unique_ptr<IEvaluator> createTrueFalse() const override {
        return make_unique<jee_lib::JEE_truefalse_eval>();
    }
};

// ---------- Demo ----------
int main() {
    // Sample responses
    string gate_mcq    = "Option A";
    string gate_fillin = "Brown Field";
    string gate_essay  = "Big Essay soon...";
    string gate_tf     = "True";

    string jee_mcq     = "Option B";
    string jee_fillin  = "Green Field";
    string jee_essay   = "Short essay draft...";
    string jee_tf      = "False";

    // Use Abstract Factory to create evaluators
    GateExamFactory gateFactory;
    JeeExamFactory jeeFactory;

    // GATE evaluation
    gateFactory.createMcq()->evaluate(gate_mcq);
    gateFactory.createFillin()->evaluate(gate_fillin);
    gateFactory.createEssay()->evaluate(gate_essay);
    gateFactory.createTrueFalse()->evaluate(gate_tf);

    // JEE evaluation
    jeeFactory.createMcq()->evaluate(jee_mcq);
    jeeFactory.createFillin()->evaluate(jee_fillin);
    jeeFactory.createEssay()->evaluate(jee_essay);
    jeeFactory.createTrueFalse()->evaluate(jee_tf);

    return 0;
}
