#include "OctNode.h"



OctNode::OctNode()
{
}


OctNode::~OctNode()
{
	for( int index = 0; index < children.size(); ++index )
	{
		delete children[ index ];
	}
}

void OctNode::AddRenderables( std::vector<Renderable*> rendsToAdd, int &counter )
{
	// If not at max depth and too many rends for one node
	if( currentDepth < maxNodeDepth && rendsToAdd.size() > maxPerNode )
	{
		printf( "    Parent %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", currentDepth, position.x, position.y, position.z,
			bounds.x, bounds.y, bounds.z );

		// Set up children
		{
			for( int index = 0; index < 8; ++index )
			{
				children.push_back( new OctNode() );
			}

			// Front Top Left
			children[0]->position.x = position.x;
			children[0]->position.y = position.y + ( bounds.y / 2 );
			children[0]->position.z = position.z;
			children[0]->bounds.x = bounds.x / 2;
			children[0]->bounds.y = bounds.y / 2;
			children[0]->bounds.z = bounds.z / 2;
			children[0]->currentDepth = currentDepth + 1;

			printf( "ftl Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 0, children[0]->position.x, children[0]->position.y, children[0]->position.z,
					children[0]->bounds.x, children[0]->bounds.y, children[0]->bounds.z );

			// Front Top Right
			children[1]->position.x = position.x + ( bounds.x / 2 );
			children[1]->position.y = position.y + ( bounds.y / 2 );
			children[1]->position.z = position.z;
			children[1]->bounds.x = bounds.x / 2;
			children[1]->bounds.y = bounds.y / 2;
			children[1]->bounds.z = bounds.z / 2;
			children[1]->currentDepth = currentDepth + 1;

			printf( "ftr Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 1, children[1]->position.x, children[1]->position.y, children[1]->position.z,
				children[1]->bounds.x, children[1]->bounds.y, children[1]->bounds.z );

			// Front Bot Left
			children[2]->position.x = position.x;
			children[2]->position.y = position.y;
			children[2]->position.z = position.z;
			children[2]->bounds.x = bounds.x / 2;
			children[2]->bounds.y = bounds.y / 2;
			children[2]->bounds.z = bounds.z / 2;
			children[2]->currentDepth = currentDepth + 1;

			printf( "fbl Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 2, children[2]->position.x, children[2]->position.y, children[2]->position.z,
				children[2]->bounds.x, children[2]->bounds.y, children[2]->bounds.z );

			// Front Bot Right
			children[3]->position.x = position.x + ( bounds.x / 2 );
			children[3]->position.y = position.y;
			children[3]->position.z = position.z;
			children[3]->bounds.x = bounds.x / 2;
			children[3]->bounds.y = bounds.y / 2;
			children[3]->bounds.z = bounds.z / 2;
			children[3]->currentDepth = currentDepth + 1;

			printf( "fbr Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 3, children[3]->position.x, children[3]->position.y, children[3]->position.z,
				children[3]->bounds.x, children[3]->bounds.y, children[3]->bounds.z );
			
		/*  ===  */

			// Back Top Left
			children[4]->position.x = position.x;
			children[4]->position.y = position.y + ( bounds.y / 2 );
			children[4]->position.z = position.z + ( bounds.z / 2 );
			children[4]->bounds.x = bounds.x / 2;
			children[4]->bounds.y = bounds.y / 2;
			children[4]->bounds.z = bounds.z / 2;
			children[4]->currentDepth = currentDepth + 1;

			printf( "btl Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 4, children[4]->position.x, children[4]->position.y, children[4]->position.z,
				children[4]->bounds.x, children[4]->bounds.y, children[4]->bounds.z );

			// Back Top Right
			children[5]->position.x = position.x + ( bounds.x / 2 );
			children[5]->position.y = position.y + ( bounds.y / 2 );
			children[5]->position.z = position.z + ( bounds.z / 2 );
			children[5]->bounds.x = bounds.x / 2;
			children[5]->bounds.y = bounds.y / 2;
			children[5]->bounds.z = bounds.z / 2;
			children[5]->currentDepth = currentDepth + 1;

			printf( "btr Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 5, children[5]->position.x, children[5]->position.y, children[5]->position.z,
				children[5]->bounds.x, children[5]->bounds.y, children[5]->bounds.z );

			// Back Bot Left
			children[6]->position.x = position.x;
			children[6]->position.y = position.y;
			children[6]->position.z = position.z + ( bounds.z / 2 );
			children[6]->bounds.x = bounds.x / 2;
			children[6]->bounds.y = bounds.y / 2;
			children[6]->bounds.z = bounds.z / 2;
			children[6]->currentDepth = currentDepth + 1;

			printf( "bbl Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 6, children[6]->position.x, children[6]->position.y, children[6]->position.z,
				children[6]->bounds.x, children[6]->bounds.y, children[6]->bounds.z );

			// Back Bot Right
			children[7]->position.x = position.x + ( bounds.x / 2 );
			children[7]->position.y = position.y;
			children[7]->position.z = position.z + ( bounds.z / 2 );
			children[7]->bounds.x = bounds.x / 2;
			children[7]->bounds.y = bounds.y / 2;
			children[7]->bounds.z = bounds.z / 2;
			children[7]->currentDepth = currentDepth + 1;

			printf( "bbr Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 7, children[7]->position.x, children[7]->position.y, children[7]->position.z,
				children[7]->bounds.x, children[7]->bounds.y, children[7]->bounds.z );
		}


		std::vector<Renderable*> frontTopLeftRends;
		std::vector<Renderable*> frontTopRightRends;
		std::vector<Renderable*> frontBotLeftRends;
		std::vector<Renderable*> frontBotRightRends;

		std::vector<Renderable*> backTopLeftRends;
		std::vector<Renderable*> backTopRightRends;
		std::vector<Renderable*> backBotLeftRends;
		std::vector<Renderable*> backBotRightRends;

		// Loop through all rends to add
		for( std::vector<Renderable*>::iterator it = rendsToAdd.begin(); it != rendsToAdd.end(); ++it )
		{
			float sphTop, sphBottom, sphBack, sphFront, sphLeft, sphRight;
			sphTop    = (*it)->m_position.y + (*it)->m_radius;
			sphBottom = (*it)->m_position.y - (*it)->m_radius;
			sphLeft   = (*it)->m_position.x - (*it)->m_radius;
			sphRight  = (*it)->m_position.x + (*it)->m_radius;
			sphBack   = (*it)->m_position.z + (*it)->m_radius;
			sphFront  = (*it)->m_position.z - (*it)->m_radius;

			// Back
			if( sphBack > position.z + (bounds.z * 0.5) )
			{
				// Top
				if( sphTop > position.y + (bounds.y * 0.5) )
				{
					// Right
					if( sphRight > position.x + (bounds.x * 0.5) )
					{
						backTopRightRends.push_back( *it );
					}
					// Left
					if( sphLeft <  position.x + (bounds.x * 0.5) )
					{
						backTopLeftRends.push_back( *it );
					}
				}
				// Bot
				if( sphBottom < position.y + (bounds.y * 0.5) )
				{
					// Right
					if( sphRight > position.x + (bounds.x * 0.5) )
					{
						backBotRightRends.push_back( *it );
					}
					// Left
					if( sphLeft <  position.x + (bounds.x * 0.5) )
					{
						backBotLeftRends.push_back( *it );
					}
				}
			}
			// Front
			if( sphFront < position.z + (bounds.z * 0.5) )
			{
				// Top
				if( sphTop > position.y + (bounds.y * 0.5) )
				{
					// Right
					if( sphRight > position.x + (bounds.x * 0.5) )
					{
						frontTopRightRends.push_back( *it );
					}
					// Left
					if( sphLeft <  position.x + (bounds.x * 0.5) )
					{
						frontTopLeftRends.push_back( *it );
					}
				}
				// Bot
				if( sphBottom < position.y + (bounds.y * 0.5) )
				{
					// Right
					if( sphRight > position.x + (bounds.x * 0.5) )
					{
						frontBotRightRends.push_back( *it );
					}
					// Left
					if( sphLeft <  position.x + (bounds.x * 0.5) )
					{
						frontBotLeftRends.push_back( *it );
					}
				}
			}
		}

		if( frontTopLeftRends.size() > 0 )
			children[ 0 ]->AddRenderables( frontTopLeftRends, counter );
		if( frontTopRightRends.size() > 0 )
			children[ 1 ]->AddRenderables( frontTopRightRends, counter );
		if( frontBotLeftRends.size() > 0 )
			children[ 2 ]->AddRenderables( frontBotLeftRends, counter );
		if( frontBotRightRends.size() > 0 )
			children[ 3 ]->AddRenderables( frontBotRightRends, counter );

		if( backTopLeftRends.size() > 0 )
			children[ 4 ]->AddRenderables( backTopLeftRends, counter );
		if( backTopRightRends.size() > 0 )
			children[ 5 ]->AddRenderables( backTopRightRends, counter );
		if( backBotLeftRends.size() > 0 )
			children[ 6 ]->AddRenderables( backBotLeftRends, counter );
		if( backBotRightRends.size() > 0 )
			children[ 7 ]->AddRenderables( backBotRightRends, counter );
	}
	// If at max depth, add all renderables to node
	else
	{
		isLeafNode = true;
		for( std::vector<Renderable*>::iterator it = rendsToAdd.begin(); it != rendsToAdd.end(); ++it )
		{
			rends.push_back( *it );
			++counter;

			//printf( "Current Depth: %d\n", currentDepth );
			//printf( "Rends count: %d\n", rends.size() );
		}
	}
}

void OctNode::DefineSize(std::vector<Renderable*> rendsToAdd)
{
	float x = FLT_MAX;
	float y = FLT_MAX;
	float z = FLT_MAX;
	float width  = 0;
	float height = 0;
	float depth  = 0;

	// Loop through all rends to add
	for( std::vector<Renderable*>::iterator it = rendsToAdd.begin(); it != rendsToAdd.end(); ++it )
	{
		float sphTop, sphBottom, sphBack, sphFront, sphLeft, sphRight;
		sphTop    = (*it)->m_position.y + (*it)->m_radius;
		sphBottom = (*it)->m_position.y - (*it)->m_radius;
		sphLeft   = (*it)->m_position.x - (*it)->m_radius;
		sphRight  = (*it)->m_position.x + (*it)->m_radius;
		sphBack   = (*it)->m_position.z + (*it)->m_radius;
		sphFront  = (*it)->m_position.z - (*it)->m_radius;


		if( sphLeft < x )
			x = sphLeft;

		if( sphBottom < y )
			y = sphBottom;

		if( sphFront < z )
			z = sphFront;


		if( sphRight > width )
			width = sphRight;

		if( sphTop > height )
			height = sphTop;

		if( sphBack > depth )
			depth = sphBack;
	}

	position.x = x;
	position.y = y;
	position.z = z;
	
	bounds.x = width  - x;
	bounds.y = height - y;
	bounds.z = depth  - z;
}

bool OctNode::Intersection( OctNode *node, kf::Ray ray ) 
{
	//if( node->currentDepth == maxNodeDepth && node->position.x > 5 && node->position.z > 5 )
		//return false;

	return true;

	// x plane lower and upper points of ray
	double xLower = ( node->position.x - ray.start().x ) / ( ray.end().x - ray.start().x );
	double xUpper = ( node->bounds.x   - ray.start().x ) / ( ray.end().x - ray.start().x );

	// Cut ray between x points
	// if ray is in x plane, lower should be in min, upper should be in max
	double rayCutMin = std::min( xLower, xUpper );
	double rayCutMax = std::max( xLower, xUpper );

	// y plane lower and upper points of ray
	double yLower = ( node->position.y - ray.start().y ) / ( ray.end().y - ray.start().y );
	double yUpper = ( node->bounds.y   - ray.start().y ) / ( ray.end().y - ray.start().y );

	// cut ray between y points
	rayCutMin = std::max( rayCutMin, std::min( yLower, yUpper ) );
	rayCutMax = std::min( rayCutMax, std::max( yLower, yUpper ) );

	// z plane lower and upper points of ray
	double zLower = ( node->position.z - ray.start().z ) / ( ray.end().z - ray.start().z );
	double zUpper = ( node->bounds.z   - ray.start().z ) / ( ray.end().z - ray.start().z );

	// cut ray between z points
	rayCutMin = std::max( rayCutMin, std::min( zLower, zUpper ) );
	rayCutMax = std::min( rayCutMax, std::max( zLower, zUpper ) );

	// Return true if max ray point is bigger than the min ray point
	return rayCutMax >= rayCutMin;
}

/*

std::vector<Renderable*> OctNode::ChildIntersection( OctNode *node, kf::Ray ray )
{
	// If child node is leaf node
	if( node->isLeafNode )
	{
		return node->rends;
	}

	std::vector<Renderable*> nodesToSearch;
	nodesToSearch.reserve( 500 );

	// For all children in node
	for( int childIndex = 0; childIndex < node->children.size(); ++childIndex )
	{
		// If ray intersects current child node
		if( Intersection( node->children[childIndex], ray ) )
		{
			// If child node is leaf node
			if( node->children[childIndex]->isLeafNode )
			{
				// Add all child node's rends to search list
				for( int numRend = 0; numRend < node->children[childIndex]->rends.size(); ++numRend )
				{
					nodesToSearch.push_back( node->children[childIndex]->rends[numRend] );
				}
			}
			// If not a leaf node
			else
			{
				std::vector<Renderable*> tempList;

				// Search all child nodes children
				tempList = ChildIntersection( node->children[childIndex], ray );

				// If temp list isnt empty
				if( tempList.size() > 0 )
				{
					// Add all temp list nodes to nodesToSearch
					for( int tempIndex = 0; tempIndex < tempList.size(); ++tempIndex )
					{
						nodesToSearch.push_back( tempList[tempIndex] );
					}
				}
			}
		}
	}
	return nodesToSearch;
}

std::vector<Renderable*> OctNode::OctTreeRayCheck( kf::Ray ray )
{
	// If child node is leaf node
	if( isLeafNode )
	{
		return rends;
	}

	std::vector<Renderable*> nodesToSearch;

	nodesToSearch.reserve( 1000 );

	// For all children in node
	for( int childIndex = 0; childIndex < children.size(); ++childIndex )
	{
		// If ray intersects current child node
		if( Intersection( children[childIndex], ray ) )
		{
			// If child node is leaf node
			if( children[childIndex]->isLeafNode )
			{
				// Add all child node's rends to search list
				for( int numRend = 0; numRend < children[childIndex]->rends.size(); ++numRend )
				{
					nodesToSearch.push_back( children[childIndex]->rends[numRend] );
				}
			}
			// If not a leaf node
			else
			{
				std::vector<Renderable*> tempList;
				tempList.reserve( 500 );

				// Search all child nodes children
				tempList = ChildIntersection( children[childIndex], ray );

				// If temp list isnt empty
				if( tempList.size() > 0 )
				{
					// Add all temp list nodes to nodesToSearch
					for( int tempIndex = 0; tempIndex < tempList.size(); ++tempIndex )
					{
						nodesToSearch.push_back( tempList[tempIndex] );
					}
				}
			}
		}
	}
	return nodesToSearch;
}

*/


/*
std::vector<Renderable*> OctNode::RayCheck( OctNode *octTree, kf::Ray ray )
{
	float tx0 = (position.x - ray.start().x) / ray.delta().x; 
	float tx1 = ((position.x + bounds.x) - ray.start().x) / ray.delta().x; 
	float ty0 = (position.y - ray.start().y) / ray.delta().y; 
	float ty1 = ((position.y + bounds.y) - ray.start().y) / ray.delta().y; 
	float tz0 = (position.z - ray.start().z) / ray.delta().z; 
	float tz1 = ((position.z + bounds.z) - ray.start().z) / ray.delta().z;

	std::vector<Renderable*> rends;
	rends.reserve( 5000 );

	ProcSubtree( rends, tx0, ty0, tz0, tx1, ty1, tz1, octTree );
	return rends;
}

void OctNode::ProcSubtree( std::vector<Renderable*> &rends, float tx0, float ty0, float tz0, float tx1, float ty1, float tz1, OctNode *node )
{
	//if( std::max( tx0, std::max( ty0, tz0 ) ) > std::min( tx1, std::min( ty1, tz1 ) ) ) 
		//return;

	float rayCutMin = std::min( tx0, tx1 );
	float rayCutMax = std::max( tx0, tx1 );

	rayCutMin = std::min( rayCutMin, std::min( ty0, ty1 ) );
	rayCutMax = std::max( rayCutMax, std::max( ty0, ty1 ) );

	rayCutMin = std::min( rayCutMin, std::min( tz0, tz1 ) );
	rayCutMax = std::max( rayCutMax, std::max( tz0, tz1 ) );

	if( rayCutMax < rayCutMin )
		return;

	if( node->isLeafNode )
	{
		rends.insert( rends.end(), node->rends.begin(), node->rends.end() );
		return;
	}

	float txM = 0.5 * (tx0 + tx1); 
	float tyM = 0.5 * (ty0 + ty1); 
	float tzM = 0.5 * (tz0 + tz1);

	ProcSubtree( rends, tx0, tyM, tz0, txM, ty1, tzM, node->children[0] );
	ProcSubtree( rends, txM, tyM, tz0, tx1, ty1, tzM, node->children[1] );
	ProcSubtree( rends, tx0, ty0, tz0, txM, tyM, tzM, node->children[2] );
	ProcSubtree( rends, txM, ty0, tz0, tx1, tyM, tzM, node->children[3] );
	ProcSubtree( rends, tx0, tyM, tzM, txM, ty1, tz1, node->children[4] );
	ProcSubtree( rends, txM, txM, tzM, tx1, ty1, tz1, node->children[5] );
	ProcSubtree( rends, tx0, ty0, tzM, txM, tyM, tz1, node->children[6] );
	ProcSubtree( rends, txM, ty0, tzM, tx1, tyM, tz1, node->children[7] );
}
*/

// Test ray
	// if leaf
		// return rends		

	// if ray is in node front half
		// if in front top half
			// if in front top left half
				// return rends

std::vector<Renderable*> OctNode::RayCheck( OctNode *octTree, kf::Ray ray )
{
	std::vector<Renderable*> rends;
	rends.reserve( 5000 );

	ProcSubtree( rends, octTree, ray );
	return rends;
}

void OctNode::ProcSubtree( std::vector<Renderable*> &rends, OctNode *node, kf::Ray ray )
{
	if( node->isLeafNode )
	{
		rends.insert( rends.end(), node->rends.begin(), node->rends.end() );
		return;
	}

	// x plane lower and upper points of ray
	double xLower = ( node->position.x - ray.start().x ) / ( ray.end().x - ray.start().x );
	double xUpper = ( node->bounds.x   - ray.start().x ) / ( ray.end().x - ray.start().x );
	// y plane lower and upper points of ray
	double yLower = ( node->position.y - ray.start().y ) / ( ray.end().y - ray.start().y );
	double yUpper = ( node->bounds.y   - ray.start().y ) / ( ray.end().y - ray.start().y );
	// z plane lower and upper points of ray
	double zLower = ( node->position.z - ray.start().z ) / ( ray.end().z - ray.start().z );
	double zUpper = ( node->bounds.z   - ray.start().z ) / ( ray.end().z - ray.start().z );

	// front
	if( zLower > node->position.z && zUpper < node->position.z + (node->bounds.z * 0.5) )
	{
		ProcSubtree( rends, children[ 0 ], ray );
		ProcSubtree( rends, children[ 1 ], ray );
		ProcSubtree( rends, children[ 2 ], ray );
		ProcSubtree( rends, children[ 3 ], ray );
	}
	// back
	if( zLower > node->position.z + (node->bounds.z * 0.5) && zUpper < node->position.z + node->bounds.z )
	{
		ProcSubtree( rends, children[ 4 ], ray );
		ProcSubtree( rends, children[ 5 ], ray );
		ProcSubtree( rends, children[ 6 ], ray );
		ProcSubtree( rends, children[ 7 ], ray );
	}
}