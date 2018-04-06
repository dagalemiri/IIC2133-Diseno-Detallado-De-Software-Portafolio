int structure_verification(Map* map, int row, int column, Cell cell)
{

	int needed_grass = 0;
	int real_grass = 0;

	int needed_road = 0;
	int real_road = 0;

	int needed_castle = 0;
	int real_castle = 0;

	if (row == 0)
	{
		needed_grass++;
	}
	else if (map->table[row-1][column].id == 0)
	{

	}
	else
	{
		if (map->table[row-1][column].down == 1)
		{
			needed_grass++;
		}
		else if (map->table[row-1][column].down == 2)
		{
			needed_road++;
		}
		else if (map->table[row-1][column].down == 3)
		{
			needed_castle++;
		}
	}

	if(row == map->height-1)
	{
		needed_grass++;
	}
	else if (map->table[row+1][column].id == 0)
	{

	}
	else
	{
		if (map->table[row+1][column].up == 1 )
		{
			needed_grass++;
		}
		else if (map->table[row+1][column].up == 2)
		{
			needed_road++;
		}
		else if (map->table[row+1][column].up == 3)
		{
			needed_castle++;
		}
	}

	if(column == 0)
	{
		needed_grass++;
	}
	else if (map->table[row][column-1].id == 0)
	{

	}
	else
	{
		if (map->table[row][column-1].right == 1)
		{
			needed_grass++;
		}
		else if (map->table[row][column-1].right == 2)
		{
			needed_road++;
		}
		else if (map->table[row][column-1].right == 3)
		{
			needed_castle++;
		}
	}

	if(column == map->width-1)
	{
		needed_grass++;
	}
	else if (map->table[row][column+1].id == 0)
	{

	}
	else
	{
		if (map->table[row][column+1].left == 1)
		{
			needed_grass++;
		}
	  else if (map->table[row][column+1].left == 2)
		{
			needed_road++;
		}
		else if (map->table[row][column+1].left == 3)
		{
			needed_castle++;
		}
	}


	if (cell.up == 1)
	{
		real_grass++;
	}
	else if (cell.up == 2)
	{
		real_road++;
	}
	else if (cell.up == 3)
	{
		real_castle++;
	}

	if (cell.right == 1)
	{
		real_grass++;
	}
	else if (cell.right == 2)
	{
		real_road++;
	}
	else if (cell.right == 3)
	{
		real_castle++;
	}

	if (cell.down == 1)
	{
		real_grass++;
	}
	else if (cell.down == 2)
	{
		real_road++;
	}
	else if (cell.down == 3)
	{
		real_castle++;
	}

	if (cell.left == 1)
	{
		real_grass++;
	}
	else if (cell.left == 2)
	{
		real_road++;
	}
	else if (cell.left == 3)
	{
		real_castle++;
	}

	if ((needed_grass <= real_grass) && (needed_road <= real_road) && (needed_castle <= real_castle))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
