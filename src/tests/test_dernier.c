/*
 *   Ce fichier fait partie d'un projet de programmation donné en Licence 3 
 *   à l'Université de Bordeaux
 *
 *   Copyright (C) 2015 Giuliana Bianchi, Adrien Boussicault, Thomas Place, Marc Zeitoun
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <automate.h>
#include <rationnel.h>
#include <ensemble.h>
#include <outils.h>
#include <parse.h>
#include <scan.h>

int test_dernier(){
	int result = 1;
    {
       Rationnel * rat;
       rat = expression_to_rationnel("a");
       numeroter_rationnel(rat);
       Ensemble * e = dernier(rat);
       
       TEST(
          1
          && rat
          && e
          && est_dans_l_ensemble(e, 1)
          && taille_ensemble( e ) == 1
          , result);
    }

    {
       Rationnel * rat;
       rat = expression_to_rationnel("a.b");
       numeroter_rationnel(rat);
       Ensemble * e = dernier(rat);
       
       TEST(
          1
          && rat
          && e
          && est_dans_l_ensemble(e, 2)
          && taille_ensemble( e ) == 1
          , result);
    }

    {
       Rationnel * rat;
       rat = expression_to_rationnel("(a.a)*.(b.c)");
       numeroter_rationnel(rat);
       Ensemble * e = dernier(rat);
       
       TEST(
          1
          && rat
          && e
          && est_dans_l_ensemble(e, 4)
          && taille_ensemble( e ) == 1
          , result);
    }

    {
       Rationnel * rat;
       rat = expression_to_rationnel("(a.a)*.(b+c)");
       numeroter_rationnel(rat);
       Ensemble * e = dernier(rat);
       
       TEST(
          1
          && rat
          && e
          && est_dans_l_ensemble(e, 3)
          && est_dans_l_ensemble(e, 4)
          && taille_ensemble( e ) == 2
          , result);
    }

    {
       Rationnel * rat;
       rat = expression_to_rationnel("(a.a)*.(b+((c+d.a)*.a)*.e)");
       numeroter_rationnel(rat);
       Ensemble * e = dernier(rat);
       
       TEST(
          1
          && rat
          && e
          && est_dans_l_ensemble(e, 3)
          && est_dans_l_ensemble(e, 8)
          && taille_ensemble( e ) == 2
          , result);
    }

    {
       Rationnel * rat;
       rat = expression_to_rationnel("(b.c).(a.a)*");
       numeroter_rationnel(rat);
       Ensemble * e = dernier(rat);
       
       TEST(
          1
          && rat
          && e
          && est_dans_l_ensemble(e, 2)
          && est_dans_l_ensemble(e, 4)
          && taille_ensemble( e ) == 2
          , result);
    }

    {
       Rationnel * rat;
       rat = expression_to_rationnel("(b+c).(a.a)*");
       numeroter_rationnel(rat);
       Ensemble * e = dernier(rat);
       
       TEST(
          1
          && rat
          && e
          && est_dans_l_ensemble(e, 1)
          && est_dans_l_ensemble(e, 2)
          && est_dans_l_ensemble(e, 4)
          && taille_ensemble( e ) == 3
          , result);
    }

    {
       Rationnel * rat;
       rat = expression_to_rationnel("(b+e.(a.(c+d.a)*)*).(a.a)*");
       numeroter_rationnel(rat);
       Ensemble * e = dernier(rat);

       TEST(
          1
          && rat
          && e
          && est_dans_l_ensemble(e, 1)
          && est_dans_l_ensemble(e, 2)
          && est_dans_l_ensemble(e, 3)
          && est_dans_l_ensemble(e, 4)
          && est_dans_l_ensemble(e, 6)
          && est_dans_l_ensemble(e, 8)
          && taille_ensemble( e ) == 6
          , result);
    }

    return result;
}

int main(int argc, char *argv[])
{
   if( ! test_dernier() )
    return 1; 
   
   return 0;
}


