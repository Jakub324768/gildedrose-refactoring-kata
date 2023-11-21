#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void decreasingQuality(Item& item)
{
    if (item.quality > 0)
    {
        item.quality--;
    }
}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {

        Item& item = items[i];

        if(item.name == "Sulfuras, Hand of Ragnaros")
        {
            continue;
        }

        if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert")
        {
            decreasingQuality(item);
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality++;

                if (item.name == "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (item.sellIn < 11)
                    {
                        if (item.quality < 50)
                        {
                            item.quality++;
                        }
                    }

                    if (item.sellIn < 6)
                    {
                        if (item.quality < 50)
                        {
                            item.quality++;
                        }
                    }
                }
            }
        }

        item.sellIn--;

        if (item.sellIn < 0)
        {
            if (item.name != "Aged Brie")
            {
                if (item.name != "Backstage passes to a TAFKAL80ETC concert")
                {
                    decreasingQuality(item);
                }
                else
                {
                    item.quality = item.quality - item.quality;
                }
            }
            else
            {
                if (item.quality < 50)
                {
                    item.quality++;
                }
            }
        }
    }
}
