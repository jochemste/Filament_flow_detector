#ifndef DEFINITIONS_H
#define DEFINITIONS_H

/** Interval to allow for slow moving components. Making this value too
 *  small will result in constant state changes and quickly changing 
 * high/low values being sent to the receiving printer. A too low value
 * will result into skipping state changes, with possibly similar results.
 * Default = 5000
 * 5 second delay between sensor reading and taking action.
 */
#define MAX_INTERVAL 1000 // 

#endif DEFINITIONS_H
