Welcome to Collision Debug Tracer (CDT)

The plugin consists of 3 features:
- Runtime visualizer of all your traces without overhead (including static meshes)
- Editor sweep visualizer dummy actor for any shape (including static meshes)
- Editor window to display all actors with specified collision profile, collision profile finder within assets

**********************************************************

Understanding the visualized data:
Red shape: Start of the sweep
Blue shape: End of the sweep
Green point: overlapping trace hit
Yellow point: blocking trace hit

**********************************************************

Runtime visualizer of traces:
In C++ replace all your World::Sweep or UWorld::Trace functions with FTraceUtility::Sweep / Trace
(eg. replace a call like this:
World->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility)
with a call like this:
FTraceUtility::LineTraceSingleByChannel(World, HitResult, Start, End, ECC_Visibility)
)

Once done, use console variables cdt.DebugDrawTraces (bool) and CVarDebugDrawTracesDuration (float) to visualize your traces both in the editor and in development builds

**********************************************************

Editor sweep visualizer dummy:
Find BP_SMTraceDummy and BP_CollisionTraceDummy blueprints and place them into your level.
For shape select the shape type, and fill your collision querry data you would normally do in the code.
For static mesh, select your chosen static mesh and fill in the querry data.

Freely move, rotate around with the actors and see the query results

**********************************************************

Editor window:
Find EUW_ShowPrimitivesOfType blueprint, right click on it and click "Run Editor Utility Widget"
Type in the collision presets you want to find, separate them with ;

(e.g. "BlockAll;NoCollision")

Buttons:
Show Collisions of prest in level - hides all actors that do not have a simple primitive of the specified collision preset (click the checkbox to print the found components to the output log)
Find Primitives of preset in assets - Searches all your blueprints for all actor primitives with the specified collision preset and prints them to the output log
UnHide All Actors - Makes all actors again visible