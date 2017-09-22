/**
* DO NOT EDIT THIS FILE.
* See the following change record for more information,
* https://www.drupal.org/node/2815083
* @preserve
**/

(function ($, Drupal) {

  'use strict';

  var blockConfigureSelector = '[data-outside-in-edit]';
  var toggleEditSelector = '[data-drupal-outsidein="toggle"]';
  var itemsToToggleSelector = '[data-off-canvas-main-canvas], #toolbar-bar, [data-drupal-outsidein="editable"] a, [data-drupal-outsidein="editable"] button';
  var contextualItemsSelector = '[data-contextual-id] a, [data-contextual-id] button';
  var quickEditItemSelector = '[data-quickedit-entity-id]';

  $(document).on('drupalContextualLinkAdded', function (event, data) {
    Drupal.attachBehaviors(data.$el[0]);

    data.$el.find(blockConfigureSelector).on('click.outsidein', function () {
      if (!isInEditMode()) {
        $(toggleEditSelector).trigger('click').trigger('click.outside_in');
      }

      disableQuickEdit();
    });
  });

  $(document).on('keyup.outsidein', function (e) {
    if (isInEditMode() && e.keyCode === 27) {
      Drupal.announce(Drupal.t('Exited edit mode.'));
      toggleEditMode();
    }
  });

  function getItemsToToggle() {
    return $(itemsToToggleSelector).not(contextualItemsSelector);
  }

  function isInEditMode() {
    return $('#toolbar-bar').hasClass('js-outside-in-edit-mode');
  }

  function toggleEditMode() {
    setEditModeState(!isInEditMode());
  }

  function preventClick(event) {
    if ($(event.target).closest('.contextual-links').length) {
      return;
    }
    event.preventDefault();
  }

  function closeToolbarTrays() {
    $(Drupal.toolbar.models.toolbarModel.get('activeTab')).trigger('click');
  }

  function disableQuickEdit() {
    $('.quickedit-toolbar button.action-cancel').trigger('click');
  }

  function closeOffCanvas() {
    $('.ui-dialog-off-canvas .ui-dialog-titlebar-close').trigger('click');
  }

  function setEditModeState(editMode) {
    if (!document.querySelector('[data-off-canvas-main-canvas]')) {
      throw new Error('data-off-canvas-main-canvas is missing from outside-in-page-wrapper.html.twig');
    }
    editMode = !!editMode;
    var $editButton = $(toggleEditSelector);
    var $editables;

    if (editMode) {
      $editButton.text(Drupal.t('Editing'));
      closeToolbarTrays();

      $editables = $('[data-drupal-outsidein="editable"]').once('outsidein');
      if ($editables.length) {
        document.querySelector('[data-off-canvas-main-canvas]').addEventListener('click', preventClick, true);

        $editables.not(contextualItemsSelector).on('click.outsidein', function (e) {
          if ($(e.target).closest('.contextual').length || !localStorage.getItem('Drupal.contextualToolbar.isViewing')) {
            return;
          }
          $(e.currentTarget).find(blockConfigureSelector).trigger('click');
          disableQuickEdit();
        });
        $(quickEditItemSelector).not(contextualItemsSelector).on('click.outsidein', function (e) {
          if (!$(e.target).parent().hasClass('contextual') || $(e.target).parent().hasClass('quickedit')) {
            closeOffCanvas();
          }

          if ($(e.target).parent().hasClass('contextual') || $(e.target).parent().hasClass('quickedit')) {
            return;
          }
          $(e.currentTarget).find('li.quickedit a').trigger('click');
        });
      }
    } else {
        $editables = $('[data-drupal-outsidein="editable"]').removeOnce('outsidein');
        if ($editables.length) {
          document.querySelector('[data-off-canvas-main-canvas]').removeEventListener('click', preventClick, true);
          $editables.off('.outsidein');
          $(quickEditItemSelector).off('.outsidein');
        }

        $editButton.text(Drupal.t('Edit'));
        closeOffCanvas();
        disableQuickEdit();
      }
    getItemsToToggle().toggleClass('js-outside-in-edit-mode', editMode);
    $('.edit-mode-inactive').toggleClass('visually-hidden', editMode);
  }

  Drupal.behaviors.outsideInEdit = {
    attach: function attach() {
      var editMode = localStorage.getItem('Drupal.contextualToolbar.isViewing') === 'false';
      if (editMode) {
        setEditModeState(true);
      }
    }
  };

  Drupal.behaviors.toggleEditMode = {
    attach: function attach() {

      $(toggleEditSelector).once('outsidein').on('click.outsidein', toggleEditMode);

      var search = Drupal.ajax.WRAPPER_FORMAT + '=drupal_dialog';
      var replace = Drupal.ajax.WRAPPER_FORMAT + '=drupal_dialog_off_canvas';

      Drupal.ajax.instances.filter(function (instance) {
        var hasElement = instance && !!instance.element;
        var rendererOffCanvas = false;
        var wrapperOffCanvas = false;
        if (hasElement) {
          rendererOffCanvas = $(instance.element).attr('data-dialog-renderer') === 'off_canvas';
          wrapperOffCanvas = instance.options.url.indexOf('drupal_dialog_off_canvas') === -1;
        }
        return hasElement && rendererOffCanvas && wrapperOffCanvas;
      }).forEach(function (instance) {
        instance.options.url = instance.options.url.replace(search, replace);

        if (!('dialogOptions' in instance.options.data)) {
          instance.options.data.dialogOptions = {};
        }
        instance.options.data.dialogOptions.outsideInActiveEditableId = $(instance.element).parents('.outside-in-editable').attr('id');
        instance.progress = { type: 'fullscreen' };
      });
    }
  };

  $(window).on({
    'dialog:beforecreate': function dialogBeforecreate(event, dialog, $element, settings) {
      if ($element.is('#drupal-off-canvas')) {
        $('body .outside-in-active-editable').removeClass('outside-in-active-editable');
        var $activeElement = $('#' + settings.outsideInActiveEditableId);
        if ($activeElement.length) {
          $activeElement.addClass('outside-in-active-editable');
          settings.dialogClass += ' ui-dialog-outside-in';
        }
      }
    },
    'dialog:beforeclose': function dialogBeforeclose(event, dialog, $element) {
      if ($element.is('#drupal-off-canvas')) {
        $('body .outside-in-active-editable').removeClass('outside-in-active-editable');
      }
    }
  });
})(jQuery, Drupal);