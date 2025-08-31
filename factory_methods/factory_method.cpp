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

// ---------- Factory Method creator hierarchies ----------
class McqCreator {
public:
    virtual unique_ptr<IEvaluator> create() const = 0;
    virtual ~McqCreator() = default;
};
class FillinCreator {
public:
    virtual unique_ptr<IEvaluator> create() const = 0;
    virtual ~FillinCreator() = default;
};
class EssayCreator {
public:
    virtual unique_ptr<IEvaluator> create() const = 0;
    virtual ~EssayCreator() = default;
};
class TrueFalseCreator {
public:
    virtual unique_ptr<IEvaluator> create() const = 0;
    virtual ~TrueFalseCreator() = default;
};

// ---------- Concrete Creators ----------
class GateMcqCreator : public McqCreator {
public:
    unique_ptr<IEvaluator> create() const override {
        return make_unique<gate_lib::GATE_mcq_eval>();
    }
};
class GateFillinCreator : public FillinCreator {
public:
    unique_ptr<IEvaluator> create() const override {
        return make_unique<gate_lib::GATE_fillin_eval>();
    }
};
class GateEssayCreator : public EssayCreator {
public:
    unique_ptr<IEvaluator> create() const override {
        return make_unique<gate_lib::GATE_essay_eval>();
    }
};
class GateTrueFalseCreator : public TrueFalseCreator {
public:
    unique_ptr<IEvaluator> create() const override {
        return make_unique<gate_lib::GATE_truefalse_eval>();
    }
};

class JeeMcqCreator : public McqCreator {
public:
    unique_ptr<IEvaluator> create() const override {
        return make_unique<jee_lib::JEE_mcq_eval>();
    }
};
class JeeFillinCreator : public FillinCreator {
public:
    unique_ptr<IEvaluator> create() const override {
        return make_unique<jee_lib::JEE_fillin_eval>();
    }
};
class JeeEssayCreator : public EssayCreator {
public:
    unique_ptr<IEvaluator> create() const override {
        return make_unique<jee_lib::JEE_essay_eval>();
    }
};
class JeeTrueFalseCreator : public TrueFalseCreator {
public:
    unique_ptr<IEvaluator> create() const override {
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

    // GATE
    GateMcqCreator().create()->evaluate(gate_mcq);
    GateFillinCreator().create()->evaluate(gate_fillin);
    GateEssayCreator().create()->evaluate(gate_essay);
    GateTrueFalseCreator().create()->evaluate(gate_tf);

    // JEE
    JeeMcqCreator().create()->evaluate(jee_mcq);
    JeeFillinCreator().create()->evaluate(jee_fillin);
    JeeEssayCreator().create()->evaluate(jee_essay);
    JeeTrueFalseCreator().create()->evaluate(jee_tf);

    return 0;
}
