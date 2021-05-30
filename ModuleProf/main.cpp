#include <iostream>
#include <vector>
using namespace std;

class Prof;
class Module
{
public:
    Module(const string &name = string());
    void display() const;
    void addProf(Prof *prof);
    string getName() const;
    void setName(const string &name);

private:
    string myName;
    vector<Prof *> myProfs;
};

class Prof
{
public:
    Prof(const string &name = string() );
    void display() const;
    void addModule(Module *module);
    string getName() const;
    void setName(const string &name);

private:
    string myName;
    vector<Module *> myModules;
};

//définition Prof
Prof::Prof(const string &name) : myName(name) {}
string Prof::getName() const { return myName; }
void Prof::setName(const string &name) { myName = name; }
void Prof::addModule(Module *pModule)
{
    myModules.push_back(pModule);
}
void Prof::display() const
{
    for (Module *pModule : myModules)
    {
        cout << pModule->getName() << endl;
    }
}

//déifinition Module

Module::Module(const string &name) : myName(name) {}
string Module::getName() const { return myName; }
void Module::setName(const string &name) { myName = name; }
void Module::addProf(Prof *pProf)
{
    myProfs.push_back(pProf);
}
void Module::display(void) const
{
    for (Prof *pProf : myProfs)
        cout << pProf->getName() << endl;
}

void testModuleProf()
{
    vector<Module *> modules;
    modules.resize(4);

    vector<Prof *> profs;
    profs.resize(4);

    // Création des modules
    for (unsigned i(0); i < 4; ++i)
    {
        string module;
        cout << "Veuillez saisir un nom de Module : (pas d'espace dans le nom)" << endl;
        cin >> module;
        cout << "bite";
        modules[i] = new Module(module);
    }

    for (unsigned i(0); i < 4; ++i)
    {
        string prof;
        cout << "Veuillez saisir un nom de Prof : (pas d'espace dans le nom)" << endl;
        cin >> prof;
        profs[i] = new Prof(prof);
    }
    // création des associations, attention si un prof est lié
    // à un module, ce module doit être lié à ce prof
    // Le prof 0 sera lié à tous les modules, le 1 à tous sauf le premier ..

    for (unsigned numProf(0); numProf < profs.size(); ++numProf)
    {
        for (unsigned numModule(numProf); numModule < modules.size(); ++numModule)
        {
            profs[numProf]->addModule(modules[numModule]);
            modules[numModule]->addProf(profs[numProf]);
        }
    }

    // affichages des profs avec leur modules assiciés
    for (const Prof *prof : profs)
    {
        cout << "Nom de professeur : " << prof->getName() << endl;
        cout << "Liste des modules associés :" << endl;
        prof->display();
        cout << endl;
    }

    // affichages des modules avec leur profs assiciés

    for (const Module *module : modules)
    {
        cout << "Nom du module : " << module->getName() << endl;
        cout << "Liste des professeurs associés :" << endl;
        module->display();
        cout << endl;
    }
    for (unsigned i(0); i < 5; ++i)
        {
            delete profs [i];
            // on aurait pu faire une boucle spécifique pour la ligne qui suit
            delete modules [i];
        }
}

void testModuleProfV2 (void)
   {
       vector <Module> modules;
       modules.resize(5);

       vector <Prof>   profs;
       profs.resize(5);

       // Création des modules

       for (unsigned i (0); i < 5; ++i)
       {
           string module;
           cout << "Veuillez saisir un nom de Module : (pas d'espace dans le nom)" << endl;
           cin >> module;
           modules [i] = module;
       }
       // Création des profs

       for (unsigned i (0); i < 5; ++i)
       {
           string prof;
           cout << "Veuillez saisir un nom de Prof : (pas d'espace dans le nom)" << endl;
           cin >> prof;
           profs [i] = prof;
       }

       // création des associations, attention si un prof est lié
       // à un module, ce module doit être lié à ce prof
       // Le prof 0 sera lié à tous les modules, le 1 à tous sauf le premier ...

       for (unsigned numProf (0); numProf < profs.size (); ++numProf)
       {
           for (unsigned numModule (numProf); numModule < modules.size (); ++numModule)
           {
               profs   [numProf]   .addModule  (&modules [numModule]);
               modules [numModule].addProf    (&profs   [numProf]);
           }
       }

       // affichages des profs avec leur modules assiciés

       for (const Prof & prof : profs)
       {
           cout << "Nom de professeur : " << prof.getName () << endl;
           cout << "Liste des modules associés :" << endl;
           prof.display ();
           cout << endl;
       }

       // affichages des modules avec leur profs assiciés

       for (const Module & module : modules)
       {
           cout << "Nom du module : " << module.getName () << endl;
           cout << "Liste des professeurs associés :" << endl;
           module.display ();
           cout << endl;
       }

       // restitution de l'espace devenue inutile

   } // testModuleProfV2()

void test(){

     Module *m1 = new Module("maths");
     Prof *p1 = new Prof("Justin");
     cout << m1->getName();
     m1->addProf(p1);
     m1->display();
}

int main()
{
    cout << "Hello World!" << endl;
//    testModuleProf();
    testModuleProfV2();
//    test();
    return 0;
}
