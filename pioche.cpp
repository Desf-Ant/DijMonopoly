#include "pioche.h"

std::vector <std::string> cartesChance{
    "Rendez-vous à la rue Claude Cazotte",
    "Avancer jusqu'à la case départ",
    "Rendez-vous à Bd Carnot. Si vous passez par la case départ, recevez 100",
    "Avancez à la rue Berbisey. Si vous passez par la case départ, recevez 100",
    "Vous êtes imposé pour les réparations de voirie à raison de 40/maison et 90/hôtel",
    "Avancez jusqu’à l'arrêt de tram Grésilles. Si vous passez par la case départ, recevez 100",
    "Vous avez gagné le prix de mots croisés. Recevez 100",
    "La banque vous verse un dividende de 50",
    "Vous êtes libéré de prison. Cette carte peut être conservée jusqu’à ce qu’elle soit utilisée ou vendue",
    "Reculez de trois cases",
    "Aller en prison. Rendez-vous directement en prison. Ne franchissez pas par la case départ, ne touchez pas 100",
    "Faites des réparations dans toutes vos maisons. Versez pour chaque maison 40. Versez pour chaque hôtel 80",
    "Amende pour excès de vitesse 35",
    "Payez pour frais de scolarité 175",
    "Amende pour ivresse 20",
    "Votre immeuble et votre prêt rapportent. Vous devez toucher 180"
};

std::vector <std::string> cartesCommu{
    "Placez-vous sur la case départ",
    "Erreur de la banque en votre faveur. Recevez 250",
    "Payez la note du médecin 25",
    "La vente de votre stock vous rapporte 25",
    "Vous êtes libéré de prison. Cette carte peut être conservée jusqu’à ce qu’elle soit utilisée ou vendue",
    "Aller en prison. Rendez-vous directement à la prison. Ne franchissez pas par la case départ, ne touchez pas 200",
    "Retournez à Belleville",
    "Recevez votre revenu annuel 100",
    "C’est votre anniversaire. Chaque joueur doit vous donner 10",
    "Les contributions vous remboursent la somme de 25",
    "Recevez votre intérêt sur l’emprunt à 7% 35",
    "Payez votre Police d’Assurance 45",
    "Payez une amende de 30 ou bien tirez une carte «CHANCE»",
    "Rendez-vous à la gare la plus proche. Si vous passez par la case départ, recevez 250",
    "Vous avez gagné le deuxième Prix de Beauté. Recevez 25",
    "Vous héritez 100"
};



Piocher(){
    if (Case::numero == 7 || Case::numero == 22 || Case::numero == 35){

    }

    if (Case::numero == 2 || Case::numero == 18 || Case::numero == 33){

    }
}
