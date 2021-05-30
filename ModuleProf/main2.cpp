/**
 *
 * \file    ModuleProf.cpp
 *
 * \authors M. Laporte
 *
 * \date    06/03/2018
 *
 * \version V1.0
 *
 * \brief   Classes Module et Prof, déclarations, définitions et tests
 *
 **/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

namespace
{

    class Prof;

    class Module
    {
            std::string          myName;
            std::vector <Prof *> myProfs;

        public:

            Module (const string & Name = string ());

            string getName (void) const;
            void   display (void) const;

            void addProf (/*const*/ Prof * prof);
            void setName (const string & Name);

    }; // Module

    class Prof
    {
            std::string       myName;
            vector <Module *> myModules;
       public:

            Prof (const string & Name = string ());

            string getName (void) const;
            void   display (void) const;

            void addModule (/*const*/ Module * module);
            void setName   (const string & Name);

    }; // Prof

// Module

    Module::Module (const string & Name /* = string () */) : myName (Name) {}

    string Module::getName (void) const { return myName; }

    void   Module::display (void) const
    {
        for (Prof * pProf : myProfs)
            cout << pProf->getName () << endl;

    } // display()

    void   Module::setName (const string & Name) { myName = Name; }

    void   Module::addProf (/*const*/ Prof * pProf)  { myProfs.push_back (pProf); }

// Prof

    Prof::Prof (const string & Name /* = string () */) : myName (Name) {}

    string Prof::getName (void) const { return myName; }

    void   Prof::display (void) const
    {
        for (Module * pModule : myModules)
            cout << pModule->getName () << endl;

    } // display()

    void   Prof::setName (const string & Name) { myName = Name; }

    void   Prof::addModule (/*const*/ Module *pModule)  { myModules.push_back (pModule); }

// Tests

    void testModuleProf (void)
    {
        vector <Module *> modules;
        modules.resize(5);

        vector <Prof *>   profs;
        profs.resize(5);

        // Création des modules

        for (unsigned i (0); i < 5; ++i)
        {
            string module;
            cout << "Veuillez saisir un nom de Module : (pas d'espace dans le nom)" << endl;
            cin >> module;
            modules [i] = new Module (module);
        }
        // Création des profs

        for (unsigned i (0); i < 5; ++i)
        {
            string prof;
            cout << "Veuillez saisir un nom de Prof : (pas d'espace dans le nom)" << endl;
            cin >> prof;
            profs [i] = new Prof (prof);
        }

        // création des associations, attention si un prof est lié
        // à un module, ce module doit être lié à ce prof
        // Le prof 0 sera lié à tous les modules, le 1 à tous sauf le premier ...

        for (unsigned numProf (0); numProf < profs.size (); ++numProf)
        {
            for (unsigned numModule (numProf); numModule < modules.size (); ++numModule)
            {
                profs   [numProf]   ->addModule (modules [numModule]);
                modules [numModule]->addProf   (profs   [numProf]);
            }
        }

        // affichages des profs avec leur modules assiciés

        for (const Prof * prof : profs)
        {
            cout << "Nom de professeur : " << prof->getName () << endl;
            cout << "Liste des modules associés :" << endl;
            prof->display ();
            cout << endl;
        }

        // affichages des modules avec leur profs assiciés

        for (const Module * module : modules)
        {
            cout << "Nom du module : " << module->getName () << endl;
            cout << "Liste des professeurs associés :" << endl;
            module->display ();
            cout << endl;
        }

        // restitution de l'espace (on remarquera la symétrie avec la création)

        for (unsigned i(0); i < 5; ++i)
        {
            delete profs [i];
            // on aurait pu faire une boucle spécifique pour la ligne qui suit
            delete modules [i];
        }

    } // testModuleProf()


    // plus d'allocation dynamique

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
                profs   [numProf]   .addModule (& (modules [numModule]));
                modules [numModule].addProf   (& (profs   [numProf]));
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

 } // namespace

int main()
{
    /*    * / testModuleProf   (); /*    */
    /*    */  testModuleProfV2 (); /*    */
    return 0;
}
