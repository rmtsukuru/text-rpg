
#include "text.h"

char class_descriptions[18][300] = {
    // Martial Classes
    "A thief with a cunning mind and a cold heart.",
    "An agile warrior of the plains, skilled with both the bow and the blade.",
    "An honorable warrior with a proud heart and an indomitable soul. You have sworn an oath of duty and justice, but your first loyalty is to your lord and master.",
    // Mystical Classes
    "A wanderer in the woods who knows how to follow the hidden trails and seek that which is unseen.",
    "A disciple of the mystical and martial arts, who has learned to quell one's mind in the pursuit of enlightenment and harden one's fists in the heat of battle.",
    "A musically-talented entertainer with an eye for daring tales and juicy gossip alike.",
    // Magical Classes
    "A servant of the dread spirits of the Night and keeper of that which lurks in darkness.",
    "A fortune-teller who speaks of things to come in the voice of gods and spirits of the land.",
    "A caretaker of the shrines who wards off supernatural threats and wields the power of the heavens. Your magic is granted to serve the great celestial spirits and to protect the people.",
    "One who speaks with the dark spirits where the shadows lie, and is feared for powerful hexes.",
    "A spiritual leader who wields power from beyond with their trance and communion with great spirits.",
    "A powerful mage and heir to a longstanding legacy of celestial magic and its attendant secret knowledge. For you, magic is literally in the blood.",
    "A summoner who commands the spirits of the depths to do one's bidding.",
    "A seeker of knowledge and power at all costs, who is able to transmute all manner of substances and harness the might of the elements themselves.",
    "An accomplished and erudite spellcaster well versed in arcane lore.",
    "A hunter of spirits and those who would attempt to use their magical power against mortals.",
    "A lost soul from the spirit world stranded in the realm of mortals for a time. One who always has to keep their true identity a secret from humans in order to blend in.",
    "A warrior who has met with a terrible fate, possessed by a spirit of immense but uncontrollable power. The blood on your hands makes you seek only to lift this curse, but you know not if it is even possible..."
};

char* getClassDescription(Class class) {
    return class_descriptions[class];
}


