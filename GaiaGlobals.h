
#ifndef GAIAGLOBALS_H
#define GAIAGLOBALS_H

namespace Gaia {




/**
 * @brief This enum describes the different map views
 */
enum View {
	TerrainView,
	EventsView,
	ContinentalDriftView,
	OceanTemperatureView,
	AirTemperatureView,
	OceanCurrentsView,
	AirCurrentsView,
	PrecipitationView,
	BiomesView, 
	LifeFormsView 
};

//These are irrelevant, we should read from a file instead.
#if 0
/**
 * @brief This enum describes the type of lifeform.
 * @note aquatic lifeforms go first in order to easily distinguish the two
 * @see AquaticLifeForms
 */
enum LifeFormType {
	Prokaryote,
	Eukaryote,
	Annelid,
	Crustacean,
	Mollusk,
	Fish,
	Cetacean,
	Amphibian,
	Insect,
	Reptile,
	Bird,
	Mammal
};

/**
 * @brief This number is the border between aquatic and non-aquatic lifeforms.
 * @see LifeFormType
 */
static const int AquaticLifeForms = 7;

/**
 * @brief This enum describes the biome.
 */
enum BiomeType {
	Rock,
	Arctic,
	Boreal,
	Desert,
	Grass,
	Forest,
	Jungle,
	Swamp
};
#endif


} //ns Gaia

#endif

