<div id="knowledge-base">
<?php
		 echo "<pre>"; print_r($node); echo "</pre>";
	?>
	<!-- START: Breadcrumbs -->
	<div id="kb-breadcrumbs">										
		<?php 
				$tid = $node->field_knowledge_base[LANGUAGE_NONE][0]['entity']->tid;
				$term_parents = $tid != "all" ? array_reverse(taxonomy_get_parents_all($tid)) : false; // Build an array of the hierarchical parents of the term 
		?>	
		<a href="/knowledge-base" id="bc-link">KB Home</a>
		<?php // TODO: Fix the breadcrumb. The parent attribute is not part of the term object as loaded. ?>
		<?php if (isset($term_parents)): // Loop through array of term parent objects to build breadcrumbs. ?>
			<?php foreach ($term_parents as $parent): ?>
						&nbsp;&nbsp;&gt;&nbsp;&nbsp;<?php echo $parent->name; ?>
			<?php endforeach; ?>
		<?php else: ?>
				&gt;&nbsp;&nbsp;<?php print t('All'); ?>
		<?php endif; ?>
	</div>
	<!-- END: Breadcrumbs -->
	
	<!-- START: "Back to List" link -->
	<div id="back-button">												
		<a href="/knowledge-base">
			<strong><span style="font-size:16px;">&laquo;</span>&nbsp;Back to List</strong>
		</a>
	</div>
	<!-- END: "Back to List" link -->
	
	 <!-- START: KB Article 
	<div id="kb-article" <?php //if ($node->do_not_translate) { // print 'class="OneLinkNoTx"';	} ?>>-->
	
	<?php
		// echo "<pre>"; print_r($node); echo "</pre>";
	?>
		<h1 id="article-title"><?php echo $node->title; ?></h1>
		<div id="article-body"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></div>

		<div id="article-author">
			<p class="info"><strong>Author: </strong><?php echo isset($node->field_article_author[0]["value"]) ? $node->field_article_author[0]["value"] : user_load($node->uid)->realname; ?></p>
			<p class="info"><strong>Creation
					Date: </strong><?php echo date('Y-m-d',$node->created); ?></p>
			<p class="info"><strong>Last
					Modified: </strong><?php echo date('Y-m-d',$node->created); ?></p>
			<div style="clear:both; font-size:0; height:0;">&nbsp;</div>
		</div>
	</div>
	<!-- END: KB Article -->

	<div style="clear:both;">&nbsp;</div>

</div>